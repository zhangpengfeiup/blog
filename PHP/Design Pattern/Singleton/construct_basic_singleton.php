<?php
    class Singleton {
	public function __construct() {

	}

	private static $instance = NULL;

	public static function getInstance() {
	    if (self::$instance == NULL) {
		   self::$instance = new self;
	      }
	      return self::$instance;
	}	
    }

    $a = new Singleton();
    $b = Singleton::getInstance();
    $c = Singleton::getInstance();
    var_dump($a === $b);  
