### 接受路由请求然后处理

yii 是如何接受请求然后通过组件处理，请求到对应的路由上面呢？

web/index.php

confit/web.php => urlManager

urlManager => [
    'enablePrettyUrl' => true,
    'showScriptName' => false,
    'enableStrictParsing' => true,
    'rules' => require(__DIR__ . '/routes.php')
]

GET /site/hello => siteController/actionHello()

POST /site/hi => siteController/actionHi()

options /site/option => siteController/actionOption()

- 最后需要知道如何拦截 option的请求



/web/index.php 中

(new yii\web\Application($config))->run();

创建、配置、运行一个应用

由 yii\web\Application  class Application extends \yii\base\Application

\yii\base\Application  => abstarct class Application extends Module 

Module class Module extends ServiceLocator

ServiceLocator class ServiceLocator extends Component

Component   class Component extends BaseObject

BaseObject class BaseObject implements Configurable

Configurable interface Configurable

