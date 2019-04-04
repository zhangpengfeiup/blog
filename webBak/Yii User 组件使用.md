### 想要实现的需求(从哪里来？）

目的：Yii使用Yii::$app->user->id获取用户的user_id，它是从session中或者cookie中获取的，因为我们现在使用的是JWT的验证方式，也就是我们获取用户的user_id和相关信息是从客户端传过来的JWT的token中获取的，所以我们就需要修改Yii2.0User组件中的代码来实现我们的需求。


### 分析

那么Yii使用user登录以后，它是怎么通过使用Yii::$app->user-id获取用户user_id 的呢？

接下来让我们一起来分析一下哈:

流程图如下：

![user组件](https://github.com/zhangpengfeiup/blog/blob/master/webBak/images/user%E7%BB%84%E4%BB%B6.jpg)


1.Yii::$app->user->id()获取用户id，这一步其实调用的是User组件，（为什么Yii::$app 可以访问User组件具体我还没有看，先不聊这一块了）又因为user组件没有id这个属性，我猜是不是调用的getId()这个方法，然后父类是否实现了__get() 的这个方法，向上找,在Component这个类中找到了__get的方法（注:method_exists这个方法是忽略大小写的，所以我们可以找到/yii/web/User 里面的getId()这个方法）

需要注意的是我们使用的Yii::$app->user->id这样写默认是走到User组件的，如果我们想要走到我们自定义的类中，我们需要在user组件中添加class这个属性

也就是 下面配置文件中的 app\library\User 这个类文件，这个是我们项目中自己定义的类文件
```
   'user' => [
            'class' => 'app\library\User',
            'identityClass' => 'app\models\User',
            'enableAutoLogin' => true,
        ],
```

2.走到yii/web/User下面的getId()这个方法
```
  public function getId()
    {
        $identity = $this->getIdentity();

        return $identity !== null ? $identity->getId() : null;
    }
```

这个方法又走到了$this->getIdentity()这个方法中

这里要明确，最后调用的是这个$identity这个类中的getId()这个方法，也就是我们config/web.php中配置的identityClass这个类

```
   'user' => [
            'class' => 'app\library\User',
            'identityClass' => 'app\models\User',
            'enableAutoLogin' => true,
        ],
```
3. $this->getIdentity()这个方法中
它是走到了ehco 'ccc' 这里，这个是我自己判断它走到哪里的标记，然后又去执行了$this->renewAuthStatus方法
```
 public function getIdentity($autoRenew = true)
    {
        
        if ($this->_identity === false) {
            if ($this->enableSession && $autoRenew) {
                try {
                    echo 'ccc';
                    $this->_identity = null;
                    $this->renewAuthStatus();
                } catch (\Exception $e) {
                    $this->_identity = false;
                    throw $e;
                } catch (\Throwable $e) {
                    $this->_identity = false;
                    throw $e;
                }
            } else {
                return null;
            }
        }

        return $this->_identity;
    }
```

4.走到了 $this->renewAuthStatus()这个方法中

这个方法主要是找到$this->identityClass,然后去执行一下该类里面的findIdentity静态方法，这个identityClass是在我们配置文件中填写的，然后通过$this->setIdentity($identity) 这个方法去设置$this->_identity这个属性，因为调用该方法的返回值是$this->_identity，也就是第3步函数中的返回值。

```
   'user' => [
            'class' => 'app\library\User',
            'identityClass' => 'app\models\User',
            'enableAutoLogin' => true,
        ],
```
也就是这个app\models\User 这个类文件中，这个方法也就是我这次要改的**重点**
这个方法从注释可以看出它是用来  更新认证状态信息的通过从session和cooke中获取的信息，注释写的很清楚，大家看的时候多多留意注释哈

主要功能就是从session和cookie 中获取用户的id值

我们的登录功能没有使用session 和cookie ,而是通过header头的Authorization 这个字段来传递token的值，从中获取用户的id，所以我需要更改这一段代码.

也就是配置文件中的class的类继承于/yii/web/user 然后重写renewAuthStatus()就可以实现我们的需求了。

```

   /**
     * Updates the authentication status using the information from session and cookie.
     *
     * This method will try to determine the user identity using the [[idParam]] session variable.
     *
     * If [[authTimeout]] is set, this method will refresh the timer.
     *
     * If the user identity cannot be determined by session, this method will try to [[loginByCookie()|login by cookie]]
     * if [[enableAutoLogin]] is true.
     */
 protected function renewAuthStatus()
    {
        $session = Yii::$app->getSession();
        $id = $session->getHasSessionId() || $session->getIsActive() ? $session->get($this->idParam) : null;

        if ($id === null) {
            $identity = null;
        } else {
            /* @var $class IdentityInterface */
            $class = $this->identityClass;
            $identity = $class::findIdentity($id);
        }

        $this->setIdentity($identity);

        if ($identity !== null && ($this->authTimeout !== null || $this->absoluteAuthTimeout !== null)) {
            $expire = $this->authTimeout !== null ? $session->get($this->authTimeoutParam) : null;
            $expireAbsolute = $this->absoluteAuthTimeout !== null ? $session->get($this->absoluteAuthTimeoutParam) : null;
            if ($expire !== null && $expire < time() || $expireAbsolute !== null && $expireAbsolute < time()) {
                $this->logout(false);
            } elseif ($this->authTimeout !== null) {
                $session->set($this->authTimeoutParam, time() + $this->authTimeout);
            }
        }

        if ($this->enableAutoLogin) {
            if ($this->getIsGuest()) {
                $this->loginByCookie();
            } elseif ($this->autoRenewCookie) {
                $this->renewIdentityCookie();
            }
        }
    }
```


重写后的代码如下:

```
<?php


namespace app\library;


use Lcobucci\JWT\Parser;

class User extends \yii\web\User
{

    // 从jwt中获取用户id，并判断是否过期
    public function renewAuthStatus()
    {
        $token = \Yii::$app->request->headers->get('Authorization', '');
        $id = null;
        if (!empty($token)) {
            $parseToken = (new Parser())->parse($token);
            $id = $parseToken->getClaim('uid');
        }

        if ($id === null) {
            $identity = null;
        } else {
            /* @var $class IdentityInterface */
            $class = $this->identityClass;
            $identity = $class::findIdentity($id);
        }
        $this->setIdentity($identity);
    }
}

```



### 配置项：

下面是user组件的配置项信息，class 字段是我们使用Yii::$app->user-id访问的时候访问的类文件信息

identityClass 是下面这段代码用到的identityClass 信息

```
$class = $this->identityClass;
$identity = $class::findIdentity($id);
````

```
 'user' => [
            'class' => 'app\library\User',
            'identityClass' => 'app\models\User',
            'enableAutoLogin' => true,
        ],
```


### 总结:

虽然我们最后只是修改了一点点代码，但是我看了user组件的使用和它里面的代码，感觉到Yii2.0的代码还是写的非常好的，命名规范还有注释，代码风格都值得我们好好学习。

看到时候虽然有点头疼，但是还是有收获的。

不要怕，慢慢看，知道你要从哪里来到哪里去，你去看源代码的时候就有目标的，会更好的接受一点。

开源代码的注释写得非常的好，我们看的时候要多结合注释进行看，看问题出现在哪里。注释描述了这个方法做是干什么的，参数是哪些，什么情况下，这些都是可以通过注释看出来的。  


### 方法（怎么看源码的）

我是跟着yii本身自带的登录模块去看的，从$model->login()方法到Yii::$app-user->login（）方法进去，然后看它如何处理的，进行断点调试

有的时候不知道为什么是这样，结合有的知识去猜它是怎么处理的，然后打断点验证

可能知道走到这一步了，那么是哪个函数或者哪个方法对它进行的调用呢？我们就去找调用它的地方。


这是一个大佬总结的怎么看源码，大家可以看看

```
看源码:

1、从简单的源码开始：别幻想一步登天

2、循序渐进:想搞定底层依赖的技术

3、一定要从Hello World 作为入口来阅读

4、抓大放小，边写注释边画图

5、反复三遍，真正理解源码

6、借力打力，参考源码分析书籍及博客

7、最后寄语:用几年时间锻造自己的核心技术


一开始阅读代码不要纠结一城一池的得失，不要每一行都一定要搞清楚它是干嘛的，而要聚集于核心逻辑和使用场景

```

### 笔记

这是我自己做的笔记，也就是我有疑问的地方，跟着这些不知道的地方进行仔细的看它是怎么实现的

那么使用Yii登录的user主键登录以后，想要以后使用Yii::$app->user->id 获取用户的user_id

那么它是怎么实现的呢？

我们使用JWT作为中间件，然后需要怎么获取呢？

组件的加载流程

放进去

拿出来

到哪里去
