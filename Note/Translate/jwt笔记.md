## jwt是什么？

JSON Web Token（JWT）是一个开放标准（RFC 7519），它定义了一种紧凑且独立的方式，用于在各方之间作为JSON对象安全地传输信息。 此信息可以通过数字签名进行验证和信任。 JWT可以使用秘密（使用HMAC算法）或使用RSA或ECDSA的公钥/私钥对进行签名。

## 为什么会有jwt,jwt 解决了什么问题

服务器端维护登录状态,使用传统Cookie和Session方案，扩展性不好。在单点登录的时候，如果共享登录状态信息，一种方案是使用session 数据持久化，写入数据库或者Redis中持久化。服务受到请求后，向持久层请求数据，万一持久层挂了，就会单点失败。

另一种方案就是服务器不保存session数据，所有数据都保存在客户端，每次请求都发回服务器，JWT就是这种方案中的一个。



jwt的组成：

- Header

```
{
  "alg": "HS256",
  "typ": "JWT"
}
```



- Payload

  ```
  {
    "sub": "1234567890",
    "name": "John Doe",
    "admin": true
  }
  ```

  

- Signature

  ```
  HMACSHA256(
    base64UrlEncode(header) + "." +
    base64UrlEncode(payload),
    secre)
  ```

  - Putting all together

## jwt实现的原理



## jwt的优点和缺点



## 我们应该注意哪些问题



使用cookie+jwt的方案前提是非跨域的单点登录（Cookie 无法自动携带至其他域名）

jwt token 泄露了怎么办？

使用https加密你的应用，返回jwt给客户端时设置httpOnly=true并且使用cookie而不是LocalStorage存储jwt，这样可以防止XSS攻击和CSRF攻击

注销和修改密码:

传统的session+cookie方案用户点击注销，服务端清空session即可，因为状态保存在服务端。但jwt的方案就比较难办了，因为jwt是无状态的，服务端通过计算来校验有效性。没有存储起来，即使客户端删除了jwt，jwt还是在有效期内，只不过处于一个游离状态。分析下痛点：注销变得复杂的原因在于jwt的无状态。

仅仅清空客户端的cookie。

清空或修改服务端的用户对应的secret,这样在用户注销后，jwt本身不变，但是由于secret不存在或改变，则无法完成校验。这也是为什么将secret设计成和用户相关的原因。

修改密码则略微有些不同，假设号被盗了，修改密码（是用户密码，不是jwt的secret之后），盗号者在原有jwt有效期内依旧可以继续访问系统，所以仅仅清空cookie自然是不够的，这时，需要强制性的修改secret



续签问题



签名的目的：

最后一步签名的过程，实际上是头部以及载荷内容进行签名。如果有人对头部以及载荷的内容解码以后进行修改，再进行编码的话，那么新的头部和载荷和签名和之前的签名就将是不一样的。如果不知道服务器加密时候用的秘钥的话，得出来的签名也一定会是不一样的。

Base64是一种编码，也就是说，它是可以被翻译回原来的样子来的。它并不是一种加密过程



参考:

https://jwt.io/introduction/

http://www.ruanyifeng.com/blog/2018/07/json_web_token-tutorial.html

http://blog.didispace.com/json-web-token-web-security/

http://blog.didispace.com/learn-how-to-use-jwt-xjf/