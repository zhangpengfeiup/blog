# blog


## 数据结构:
Todo:

### 1 数组
- [什么是数组？](./DataStructure/Array/数组定义.md)
- [数组是如何实现随机访问的？](./DataStructure/Array/数组随机访问.md)
- [使用malloc新建二维数组](./DataStructure/Array/%E5%88%9D%E5%A7%8B%E5%8C%96%E4%BA%8C%E7%BB%B4%E6%95%B0%E7%BB%84.md)
- [ 数组中查找元素、添加元素的时间复杂度分析](./DataStructure/Array/数组中查找元素、添加元素的时间复杂度分析.md)
- [实现一个支持动态扩容的数组](./DataStructure/Array/数组动态扩容.md)
- [实现一个大小固定的有序数组，支持动态增删改操作](./DataStructure/Array/创建固定大小的有序数组，实现增删查改.md)
- [实现两个有序数组合并为一个有序数组](./DataStructure/Array/合并两个有序数组.md)

### 2 链表
- [单链表](./DataStructure/Link/单链表.md)
- [单链表反转](./DataStructure/Link/单链表反转.md)
- 两个有序链表的合并
- 求链表的中间结点（若长度为偶数，返回前面的节点）
- 求链表的倒数第k个节点
- 删除链表倒数第n个结点
- 判断链表中是否存在环
- 求链表中环的入口节点
- 判断两个无环链表是否有交叉点
- 判断两个有环链表是否有交叉点
- 连个链表的第一个公共节点
- 单链表快速排序
- 单链表归并排序
- 双向链表
- 循环链表
- 链表中查找元素、添加元素的时间复杂度分析
- 数组和链表的不同区别在哪里
- 使用链表实现LRU

### 3. 栈
- 栈的基本概念
- 顺序栈
- 链式栈
- 栈是否为空
- 括号匹配
- 如何实现浏览器的前进和后退

### 4. 队列
- 队列的基本概念
- 顺序队列
- 链式队列
- 循环队列
- 队空和队满的判断条件
- 阻塞队列
- 并发队列

### 5.串
- 字符串匹配
- BF算法
- RK算法
- KMP算法
- Trie树
- AC自动机
### 6. 树
- 树的定义
- 树的抽象类型以及表示方法
- 二叉树的定义
- 二叉树的抽象类型和表示方法
- 二叉树
- 二叉树的深度
- 二叉树的宽度
- 二叉树的镜像
- 判断二叉树是否对称
- 判断二叉树是否是平衡二叉树
- 不分行从上到下打印二叉树（所有的值一行输出）
- 分行从上到下打印二叉树，同一层的节点按从左到右的顺序打印，每一层打印一行
- 之字形打印二叉树，第一层按照从左到右的顺序打印，第二层按照从右到左的顺序打印，第三层再按照从左到右的顺序打印，以此类推
- 二叉搜索树的第k大节点（中序遍历）
- 二叉查找树
- 平衡二叉树
- 递归树
- LSM树
- 红黑树
	
### 7. 图
- 图的定义
- Dijkstra最短路径算法
- [邻接表的创建](./DataStructure/Graph/邻接表.md) (数组 + 链表 = 邻接表)

### 8. 排序
- [Asort 由TwoSum想到asort](https://github.com/zhangpengfeiup/leetcode/blob/master/algorithms/Two%20Sum/Two%20Sum.c)
- 冒泡排序
- 插入排序
- 选择排序
- 快速排序
- 归并排序
- 桶排序
- 时间复杂度和空间复杂度分析
- 如何根据年龄给100万用户数据排序
- 通用的高性能的排序函数

### 9. 查找
- 二分查找
- 二分查找的应用和变形

### 10. 跳表

### 11.Hash Table

### 12.堆

##  算法

### 贪心算法

### 分治算法

### 动态规划

### 回溯法
- [八皇后](./Algorithm/八皇后.md)

- [简单0-1背包](./Algorithm/简单0-1背包.md)

### Manacher's Algorithm
- [Manacher's Algorithm 马拉车算法](https://github.com/zhangpengfeiup/leetcode/blob/master/algorithms/Longest%20Palindromic%20Substring/Longest%20Palindromic%20Substring%20of%20Manacher's%20Algorithm.c)

- [Manacher's Algorithm - Linear Time Longest Palindromic Substring - Part 1](https://www.geeksforgeeks.org/manachers-algorithm-linear-time-longest-palindromic-substring-part-1/)

- [Manacher's Algorithm - Linear Time Longest Palindromic Substring - Part 2](https://www.geeksforgeeks.org/manachers-algorithm-linear-time-longest-palindromic-substring-part-2/)

- [Manacher's Algorithm - Linear Time Longest Palindromic Substring - Part 3](https://www.geeksforgeeks.org/manachers-algorithm-linear-time-longest-palindromic-substring-part-3-2/)

- [Manacher's Algorithm - Linear Time Longest Palindromic Substring - Part 4](https://www.geeksforgeeks.org/manachers-algorithm-linear-time-longest-palindromic-substring-part-4/)

### Hash算法



## 计算机网络
### 物理层
- 集线器(Hub)：集线器是指对接收到的信号进行再生整形发达，以扩大网络的传输距离，同时把所有节点集中在以它为中心的结点上。它发送数据时都是没有针对性的，而是采用广播的方式发送，也就是说当要向某节点发送数据时，不是直接把数据发送到目的节点，而是把数据包发送到与集线器相连的所有节点。

### 链路层
- 交换机(Switch):是一种用于电(光)信号转发的网络设备。它可以接入交换机的任意两个网络结点提供独享的电信号通路。集线器本身不能识别MAC地址和IP地址，交换机内部的CPU会在每个端口成功连接时，通过将MAC地址和端口对应，形成一张MAC表，在以后的通讯中，发往MAC地址的数据包仅送往其对应的端口，而不是所有的端口。 

### 网络层
#### ICMP
#### IP
- IP是地址，可以理解为门牌号有定位功能
- Mac地址是身份证，没有定位功能
- IP地址分类 （A/B/C/D/E），IP分公有IP和私有IP.
- CIDR(无类型域间选路),10.100.122.2/24（前24位是网络号，后8位是主机号）
- 广播地址:主机标识段全为1
- 子网掩码:结合IP地址一起使用，用来指明一个IP地址的那些位是主机所在的子网，那些位是主机的位掩码。主要作用就是将某个IP地址分成网络地址和主机地址两部分
- 网络号: 子网掩码和ip地址按位与
- 只要是在网络上跑的包，都是完整的，可以有下层没上层，绝对不可能有上层没下层
- 当网络包到达下一个城关的时候，可以通过路由表得到下一个城关的IP地址，直接通过IP地址找就可以了，为什么还要通过本地的MAC地址呢?

####DHCP
- DHCP(Dynamic Host Configuration Protocol)是一个局域网的网络协议，使用UDP协议工作，主要用于内部网络或网络服务供应商自动分配IP地址。
- DHCP协议主要是用来给客户租用IP地址，和房产中介很像，要商谈、签约、续租，广播还不能抢单
### 传输层
#### TCP
- TCP和UDP有什么区别？
- 描述一下TCP三次握手和四次挥手的过程
- TCP有哪些状态
- TCP的LISTEN状态是什么
- TCP的CLOSE_WAIT状态是什么
- 建立一个socket连接要经历哪些步骤
- 你是如何理解TCP协议的
- 滑动窗口
- 粘包

#### UDP


### 应用层
#### HTTP
- 常见的HTTP状态码有哪些
- 301和302有什么区别
- 504和500有什么区别
- HTTPS和HTTP有什么区别
- 谈谈你所理解的HTTP协议？



## 数据存储
#### MySQL
- 订阅分库分表的Binlog是怎么订阅的
- 分库分表的数据源中加入存在主键冲突要怎么解决
- MySQL的存储引擎用的是什么？为什么选InnoDB?
- MySQL的聚簇索引和非聚簇索引有什么区别
- B+树和二叉树有什么区别和优劣

#### ClickHouse
- 什么是列式数据库
- 列式数据库和常用的数据库如MySQL有什么区别
- ClickHouse 的特点是什么

#### Redis
- Reids 支持哪些数据结构
- 每种数据结构的底层是怎么实现的
- 为什么在业务中使用Redis,Redis有什么优点
- 使用过Redis在哪些场景
- ZSET是怎么实现的？如何实现跳表
- 分布式锁

## 数据处理与数据分析

## 操作系统
- 进程和线程的区别
- 什么是多线程
- 线程间通信的多种方式


## 编程语言
#### C
- 如何动态计算数组的大小:使用sizeof,sizeof(arr) / sizeof(arr[0])
- typedef 的用法


##### PHP

##### Golang
- goroutine是怎么调度的
- goroutine和kernel thread 之间是什么关系
- Go 和 PHP 和 C 的区别，以及三者的GC
- Golang的gc算法
- Golang的逃逸分析是什么？怎么避免内存taoyi
- Golang的GC触发时机是什么

## 设计模式
- 为什么要使用设计模式
- 使用设计模式解决了是问题
- 如何高效或者什么场景下更适合使用设计模式
- 单例
- 工厂
- 观察者

## 版本控制
#### Git
- 为什么要引入版本控制
- 使用版本控制有什么需要注意的地方
- Git和Svn的区别
- Git常用的命令有哪些


## 中间件

#### 消息队列
- 为什么要使用消息队列
- 使用消息队列解决了什么问题
- 引入消息队列对系统或者架构有什么影响
- 使用消息队列有什么好处
- 使用消息队列有什么需要注意的地方或者说是坏的地方
 
#### Kafka
- Kafka的消费者是如何进行消息去重的

#### Kubernetes
- Kurbernets是什么？可以用来做什么
- 用了Kurbernets之后解决了哪些问题
- Kubernets 的Service 是什么概念？怎么实现的
- Informer 是怎么实现的？有什么作用
- StatefulSet用过吗？有什么特点，滚动升级是如何实现的
- Kubernets的所有资源约定了版本号，为什么要这么做
- 假如有多个版本号并存，那么K8s服务端需要维护几套代码
- Kubernets的架构是怎么样的

#### Docker
- 为什么要使用Docker
- Docker解决了什么问题

#### Prometheus 


## 架构设计
- 什么是微服务？为什么要用微服务？
- 谈一谈对微服务的理解
- 如何进行限流
- 文章的评论量非常大，比如说一篇热门文章有几百万的评论，设计一个后端服务，实现评论的时序展示与分页
- 分库分表如何设计？垂直平分、水平拆分？
- 业务ID的生成规则

#### 缓存设计
- 什么时候应该使用缓存
- 缓存应该怎么设计
- 缓存解决了什么问题
- 如何更好的使用缓存
- Redis 和 Memcache 选择哪一种作为缓存服务，为什么这样选择
- 缓存雪崩怎么处理
- 缓存服务器挂了怎么解决 


## 软件设计
- 泛型编程
- 函数式编程
- 面向对象编程
- DRY-避免重复原则
- KISS-简单原则
- 迪米特法则
- 面向对象的S.O.L.I.D原则


## 工程能力
- 如何定位一个线上问题（CPU高负载）

## 成长
- Self-examination（自我审视）
- 反思自己
- 职业规划
- 态度：空杯心态，很强的学习能力和进取心
- 程序员修养

## 思考:
 - [由数据结构想到拼积木](./DataStructure/Think/由数据结构想到拼积木.md)
 - 如何阅读源码
 - [生活无需对比，没有对比就没有伤害，于代码和工程，需对比，反思、调整、打磨、改进、交付](https://github.com/zhangpengfeiup/blog/blob/master/Thinking/%E7%94%9F%E6%B4%BB%E6%97%A0%E9%9C%80%E5%AF%B9%E6%AF%94%EF%BC%8C%E4%BB%A3%E7%A0%81%E9%9C%80%E8%A6%81%E6%80%9D%E8%80%83.md)
## Ask Myself
- 接下来应该做什么可以继续提升？
- 我在硬性技能（编码、架构）上有什么长处？
- 我在软技能（沟通，团队）有什么优点？
- 我是谁？
- 我在哪？
- 我要干什么？
- 我要去哪？
- 我应该干什么？
- 我现在在干什么？
- 我现在应该干什么？

## 2019 猛啃书本，不破楼兰终不还
- 学习建议from左耳朵耗子

- 一定要坚持，要保持长时间学习，甚至终生学习的态度
- 一定要动手，不管例子多么简单，建议至少自己动手敲一遍看看是否理解了里头的细枝末节
- 一定要学会思考，思考为什么要这样，而不是那样，还要举一反三地思考
- 不要乱买书，不要乱追技术新名词，基础的东西经过很长时间积累，会在未来至少10年通用
- 回顾一下历史，看看历史时间线上技术的发展，你才能明白明天会是神马样的


## 程序员的修养
- 英文能力
- 问问题的能力
- 写代码的修养，代码规范，单元测试,Code Review
- 安全防范
- 软件工程和上线

## 参考书籍和文章:
《C语言程序设计：现代方法：第2版》

《大话数据结构》

《算法：C语言实现（第1-4部分）》

《现代操作系统》

《计算机网络》

《数据库系统概念》

《数据结构与算法之美》（极客时间专栏）

《趣谈网络协议》（极客时间专栏）

[常见单链表面试题](https://blog.csdn.net/LYHVOYAGE/article/details/82915988)

[二叉树常见面试题](https://blog.csdn.net/LYHVOYAGE/article/details/82916652)

[一位大牛的后端社招面试经历] (https://github.com/aylei/interview)