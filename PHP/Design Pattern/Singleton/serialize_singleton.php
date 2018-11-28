<?php 
class Singleton {
    private static $instance = NULL;
 
    /** 不容许直接调用构造函数 */
    private function __construct() {
 
    }
 
    /** 不容许深度复制 */
    private function __clone() {
    }
 
    public  function __wakeup() {
        self::$instance = $this;
    }
 
    /** 需要在单利切换的时候做清理工作 */
    public function __destruct() {
        //只做清理工作.
    }
 
    public static function getInstance() {
        if (NULL === self::$instance) {
            self::$instance = new self();
        }
 
        return self::$instance;
    }
}

$a = Singleton::getInstance();
$a = unserialize(serialize($a));
 
var_dump($a === Singleton::getInstance());
