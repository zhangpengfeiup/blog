- 代码优化:

曾经以为写代码实现最后结果就可以了，没有思考怎么样实现会更好，看到比较好的代码或者思路也不去学习和改进，这种思维和想法是错误的，需要改变，写代码是一个思考的过程，我们需要鲁棒性好同时也更好理解的代码，代码的运行效率也应该比较高。自己写的代码效率不高，还不去改进，这样怎么会进步呢？看到比较好的代码，觉得不好理解，就放任不管了，这样是不可能进步的，所有自己需要不断反思，改进。生活中也是这样，犯错了，去思考，改正，调整，不能逃避，直面矛盾。

例如：使用Go写了一个闭包实现 Fibnoacci() 函数，自己写的代码使用了4个变量还有逻辑判断，然而优秀的代码只需要三个代码，而且代码量还比较少

```
package main

import "fmt"

func fibonacci() func() int {
      ret := 0
      num := 0
      front := 0
      last := 1
      return func() int {
           if num == 0 {
              ret = 0
          }else if num == 1 {
                ret = 1
          }else {
                ret = front + last
                front = last
                last = ret
          }
          num++
          return ret
      }
}


func main() {
   f := fibonacci()
   for i := 0;i < 10;i++ {
        fmt.Println(f())
   }
}

```

厉害的代码如下[from](https://gist.github.com/weppos/7843653)
很简单的实现了Fibonacci

```
package main

import "fmt"

// fibonacci is a function that returns
// a function that returns an int.
func fibonacci() func() int {
	f2, f1 := 0, 1
	return func() int {
		f := f2
		f2, f1 = f1, f+f1

		return f
	}
}

func main() {
	f := fibonacci()
	for i := 0; i < 10; i++ {
		fmt.Println(f())
	}
}
```