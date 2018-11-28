<?php
  class Singleton {
	 public static $instance = NULL;
	
         protected function __construct() {

         }
        
         //private  function __construct() {

         //}	

         public static function getInstance() {
		if (self::$instance == NULL) {
		     self::$instance = new self;
		}
		return self::$instance;
	 }	 
   }

   $a = Singleton::getInstance();
   $b = clone($a);

    var_dump($a === $b);
