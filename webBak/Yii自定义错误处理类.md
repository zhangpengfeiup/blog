### 需求:
我们使用Yii2.0框架做一个前后端分离的项目，其中使用了中间件(借鉴了Laravel的思想是使用了Yii2.0中的behaviors进行实现，具体实现还没有来得及看，后面看过可以给大家分享一下)判断用户携带了的token是否正确，我们项目中使用了JWT来进行用户判断，当jwt认证失败或者用户没有传过来token的值的时候，中间件抛出异常，我们需要对这个异常进行捕获，返回给前端json类型的参数，否者前端无法进行判断。

那么怎么自定义错误显示呢？

这个时候正确的第一想法首先要去yii2.0的官网中看一下,然而我不是这样做的，我们还有一个项目使用了自定义错误处理，所以我就参考了另一个项目。

### 出现问题:
另一个项目中完全可以使用，我的项目中参考另外一个项目中的代码和配置无法使用，笑哭了......

遇见这个问题的时候:我们要提醒自己别慌，从头开始分析,一步步解决它。

下面是我们组大神写的自定义错误处理，大致意思判断是否是Ajax请求，如果是返回json信息，如果不是，返回html信息，我们这个文件是放在/app/libary/ErrorAction 这个类继承于 \yii\web\ErrorAction.

但是我的接口一直返回html信息，没有返回json信息，这个时候就有点疑问了，代码都是一样的，为什么另一个项目可以跑，放到自己项目中不可以跑呢？相信大家都遇到过这个问题，那么我们一起来分析分析它吧。


### 分析过程
1. 首先我思考，php的异常处理，都是try catch 的，我中间件里 throw 出来的 Exception 这个是我自己定义的异常处理类接受的，所以我们可以去看一下yii2.0的文档

2. 官方文档如下,我们想实现的是自定义错误提示，我们通过使用错误动作的方式去实现:

使用错误动作：
使用指定的错误操作 来自定义错误显示更方便， 为此，首先配置errorHandler组件的 errorAction 属性， 类似如下：
```
return [
    'components' => [
        'errorHandler' => [
            'errorAction' => 'site/error',
        ],
    ]
];
```

errorAction 属性使用 路由到一个操作， 上述配置表示不用显示函数调用栈信息的错误会通过执行site/error操作来显示。

可以创建 site/error 动作如下所示：

```
namespace app\controllers;

use Yii;
use yii\web\Controller;

class SiteController extends Controller
{
    public function actions()
    {
        return [
            'error' => [
                'class' => 'yii\web\ErrorAction',
            ],
        ];
    }
}
```

上述代码定义error 操作使用yii\web\ErrorAction 类， 该类渲染名为error视图来显示错误。

除了使用yii\web\ErrorAction, 可定义error 动作使用类似如下的操作方法：

```
public function actionError()
{
    $exception = Yii::$app->errorHandler->exception;
    if ($exception !== null) {
        return $this->render('error', ['exception' => $exception]);
    }
}
```

现在应创建一个视图文件为views/site/error.php，在该视图文件中，如果错误动作定义为yii\web\ErrorAction， 可以访问该动作中定义的如下变量：

name: 错误名称
message: 错误信息
exception: 更多详细信息的异常对象，如HTTP 状态码， 错误码，错误调用栈等


3.结合官方文档，分析我们的代码，我们的是自定义的ErrorAction,也就是配置的是这样的,使用的是\app\library\ErrorAction, 这个类继承于 yii\web\ErrorAction来实现我们自己的代码，因为这个里面的代码不是我写的，就不贴出来的，大致意思就是判断请求是否为ajax请求或者header 头是否为appliction/json,如果是的话就以自定义json的方式返回

```
public function actions()
    {
        return [
            'error' => [
                'class' => '\app\library\ErrorAction',
            ],
            'captcha' => [
                'class' => 'yii\captcha\CaptchaAction',
                'fixedVerifyCode' => YII_ENV_TEST ? 'testme' : null,
            ],
        ];
    }
```

4.我们看官方文档和对比代码分析出来，我们的异常处理是由yii内置的一个error handler 错误处理器，我们配置的是错误处理器里面的errorAction 也就是错误动作，所以，我们的错误动作是在**SiteController** 里面的，因为我们配置的错误动作是site/error,这里是重点了，所以接下来我们配置的actions 信息和actionEroor() 都在**SiteController**里面的，然后就可以使用了。

5.这个时候大家就有一个问题了，为什么你一开始没有注意到这么简单的问题呢，因为我一开始看的是另一个项目中的代码，另一个项目中的SiteController 集成与BaseController，但是我这个是新的项目没有继承于BaseController里面，所以就没有注意到这一点。总而言之，还是没有仔细看官方文档吧，mark了，有的时候看官方文档的时候觉得理解了，到自己用的时候发现不是那么回事，不知道大家是不是也有这样的感觉，有这种感觉应该还是没有理解吧。

6.下次遇到这种问题,怎么解决？ 

6.1 首先要分析清楚需求，从哪里来，到哪里去？理论先行，实践验证

6.2 看官方文档，如果有项目使用，可以作为参考，但是一定要看官方文档，看官方文档，看官方文档，一官方文档为准，然后就是分析清楚以后理论先行，实践验证了。

7.JWT 资料:

[JSON Web Token 入门教程](http://www.ruanyifeng.com/blog/2018/07/json_web_token-tutorial.html)

[JWT GitHub](https://github.com/lcobucci/jwt)

[JWT 使用文档](https://github.com/lcobucci/jwt/blob/3.2/README.md)

JWT使用signature的时候主要有两种方法，use得时候不要use错了，要不验证不成功的，我都是use错了，和同事讲了一下，然后才找到问题的。

### 总结

遇到问题要明确从哪里来，到哪里去？

然后分析清楚，理论先行，实践验证

查资料的话如果官方文档上面有的话仔细看官方文档

耐心一点，仔细分析

