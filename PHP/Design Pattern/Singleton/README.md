Why use singleton?

	From the PHP right way.  https://phptherightway.com/pages/Design-Patterns.html 
	When designing web applications, it often makes sense conceptually and architecturally to allow access
	to one and only one instance of a particular class. The singleton pattern enables us to do this.

	in no_singleton.php  we find the var_dump($a === $b) is false
	
	in basic_singleton.php we create the basic singletong,in current the var_dump($a === $b) is true
	
	in construct_basic_singleton.php the construct set is public,so we can use the new Singleton.var_dump($a === $b) is false. so we do not want use the new operator outside the class.
	so we should set the function __construct is private or protected.
	in the php right way, it is said 
	The constructor __construct() is declared as protected to prevent creating a new instance outside of the class via the new operator.
	
	clone_singleton.php  if we not set the clone function is private or protected. it will be cloned. In the last, the var_dump($a === $b) will false.so we need set the function clone is private or protected.
	in the php right way. The magic method __clone() is declared as private or protected to prevent cloning of an instance of the class via the clone operator.
	
	wakeup_singleton.php if we not set the function of __wakeup(). when we use serialize and unserialize, we will find the var_dump($a === $b) is false.
	
	so the singleton is in the singleton.php,you can read it.
	
	In the first, I think the singleton is not difficult.But when I analyze it by myself. I find everything is not easy. It all need we put out heart in it.And do it better.
	
	But if we want the singleton can serialize. What should we do?
	You can read laruence answer http://www.laruence.com/2011/03/18/1916.html