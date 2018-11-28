<?php
class Singleton {
     private static $instance = NULL;

     protected function __construct() {

     }
	
     protected function __clone() {

    }
  
    private function __sleep() {

    }

    private function __wakeup() {

    }

     public static function getInstance() {
	    if ($instance == NULL) {
		self::$instance = new self;
	     }
	     return self::$instance;
     }
}

$a = Singleton::getInstance();
$b = unserialize(serialize($a));

var_dump($a === Singleton::getInstance());
