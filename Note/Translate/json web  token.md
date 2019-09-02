- 什么时候你应该用 json web  token?

  ​	这里是jwt比较有用的一些场景

  authorization: 这个是一个常见的场景对于使用jwt. 一旦用户登录了，每个子请求将包含JWT,允许用户进入路由、服务、静态资源这些被token允许的场景。单点登录是当下广泛使用jwt的一个场景，因为它的小的 overhead 和它很方便的使用通过不同的域名

- 信息交换

    jwt 是一个很好的方式在不同的地方之间安全的传递消息的一种方式。因为JWT可以被登录。例如：使用公钥私钥对，你可以确认发送者的身份信息，除了这样，当签名被声明在头部和payload

  中，你也可以确认内容是否被分割。

- JWT 的数据结构有哪些？

   在它的组成当中，JWT包含3个部分，通过. 分割开来，它们是 Header,Payload,Signature.

因此，一个JWT通常看起来是下面这样:

xxxx.yyyy.zzzz

让我们分解成不同的部分

- Header

  头部通常包含两部分：token的类型，JWT,以及使用了那种签名算法，例如HMAC SHA256 或者是RSA.

  例子如:

  {	

  ​    "alg":"HS256",

  ​    "type":"JWT"

  }

接下来，这个json是Base64Url 加密组成JWT的第一部分



- Payload

   token的第二部分是payload,它包含了claims. claims 是一个声明关于实体(通常，这个用户)和一些额外的数据。这里是三部分claims的声明：registered,public,和private cliams.

  Registered claims:这里有有一些提前定义好的claims这些不是mandatory 强制的但是是建议的，为了提供一个集合或者是有用的，内部操作的claims. 他们其中的一些是:iss(issuer),exp(expiration time),sub(subject),aud(audience),and others.

  注意claim 名字是一个只允许3个字符，因为jwt是比较简洁的。

  - Public claims: 这些可以用来定义通过使用JWTS.但是为了避免collisions 他们应该被定义在IANA JSON Web Token Registry 或者被定义作为URI他们包含 collision 相关的命名

  - Private cliams:这些客户声明被创建在部分之间用来分享信息并且不允许在registered 或者是public claims.

  一个 payload的例子如下所示:

  ```
  {
     "sub":"1234567890",
     "name":"John Doe",
     "admin":true
  }
  ```

  这个payload使用Base64Url加密用来组成JSON Web Token的第二部分

  

  请记住加密过得token是信息，尽快避免分割，但是可以被每个人看到。所有不要放一些比较私密的信息在payload或者头部的结点中除非它已经加密过了

  

  - Signature

    为了创建加密部分，有不得不采用加密的头部、加密的payload，一个secret,加密的算法在头部指出，并且加密它。

    例如，如果你想使用HMAC SHA256 算法，这个加密的内容将要以下面这种方式创建:

    ```
    HMACSHA256(
    base64UrlEncode(header) + "." +
    base64UrlEncode(payload),
    secret
    )
    ```

    

  这个密文被用来验证这些信息在传输的过程中没有被改变，并且，在这个例子中token 被private key 用来加密，它也可以用来判断JWT是谁发送的

- 把他们放一起

这个输出是三个Base64-URL 字符串被.分隔开可以简单的通过HTML和HTTP的环境，然而作为更加简洁当用来对比 XML-based 标准例如SAML.

以下显示了一个JWT拥有上面的header和payload的加密，以及通过secret进行加密。

如果你想使用JWT并且将这些概念用到实践中，你可以使用jwt.io 进行debug 为了解密，验证，并进行构建JWT.

- JSON Web tokens 是怎么工作的？

  在 authentication,当用户成功登陆通过使用credentials,一个Json Web Token 将要返回。由于token 是 credentials,greate care must be taken to prevent security issues.通常来说，你不应该长时间的保留tokens。

  你不应该存储敏感数据在浏览器的storage由于缺少安全性

  

  当用户想要进入受保护的路由或者资源的时候，这个用户浏览器端会发送JWT，通常在Authorization header头中使用Bearer的schema.这个内容像下面这样:

  

  

  Authorization:Bearer <token>

  

  就是这样，在一些例子中，一些无状态的mechanism. 这个服务访问受保护的路由将要检查不合法的JWT在Authoriztion 头部中，并且如果它是当前的，这个用户将要由于进入受保护的路由。如果JWT包含不被允许的数据，访问数据库的权限或者合适的操作可能被reduced取消，因为这个在这个例子中不被允许。

  

  如果这个token 被发送在Authorization头部中，跨域请求（CORS）将不是一个问题因为它没有使用cookies.

  

  接下来的图标展示JWT被包含以及被用来访问API或者资源

  1.  应用或者客户端发送authoriztion到authoriztion服务端。这个被看作通过其中一个不同的认证模型。例如：一个典型的OpenID connect web 客户端将要进入 /oauth/authorize 最后节点使用了 authoriztion code flow.
  2. 当这个authoriztion 被授权，这个authorization 服务器返回一个可以进行访问的token给客户端
  3. 这个客户端可以使用token进入受保护的资源（像api一样）

  Do not that signed tokens, 所有的信息包含在token里面的都暴露给用户或者其他部分，尽管它是不可以改变的。它意味着你不能放私密的信息在token里面

- 为什么我们应该使用JSON Web Tokens？

  让我们讨论jwt的好处当用来对比Simple Web Tokens 和Security Assertion Markup Language Tokens(SAML)

  因为json是比较少 verbose 比 xml,当它加密以后它的大小同样小，这样使JWT更加简洁对比SAML.这样使JWT是一个很好的选择在HTML和HTTP环境中进行传输

  更加容易加密，SWT仅仅被symmetrically signed 通过一个分享的secret 使用HMAC算法。然后JWT 和 SAML tokens 可以使用 pulbic/private 密钥对在form of X.509中用来加密。Signing XML

没有介绍obscure security holes is very difficult when compared to the simplicity of signing JSON.

