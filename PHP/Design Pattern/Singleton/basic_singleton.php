<?php
     class Study {
	 public static $instance = NULL;

         public static function getInstance() {
		if (self::$instance == NULL) {
		     self::$instance = new self;
		}
		return self::$instance;
	 }	 
   }

    $a = Study::getInstance();

    $b = Study::getInstance();

    var_dump($a === $b);

