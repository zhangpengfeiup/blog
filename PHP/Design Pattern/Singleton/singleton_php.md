```
<?php
class Singleton {
	private static $instance = NULL;
	// avoid construct
	protected function __construct() {

	}
	//avoid clone
	protected function __clone() {

	}
	//avoid serialize
	private function __sleep() {

	}
	//avoid unserialize
	private function __wakeup() {

	}

	public static function getInstance() {
		if (self::$instance == NULL) {
		    self::$instance = new self;
		}
		return self::$instance;
	}
}

$a = Singleton::getInstance();
$b = Singleton::getInstance();
var_dump($a === $b);
```

