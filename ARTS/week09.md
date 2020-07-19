Algorithm:

递归  分治 🤔
```
/**
 * Definition for TreeNode.
 * type TreeNode struct {
 *     Val int
 *     Left *ListNode
 *     Right *ListNode
 * }
 */
 func lowestCommonAncestor(root, p, q *TreeNode) *TreeNode {
     if root == nil {
         return nil
     }
     
     if root.Val == p.Val || root.Val == q.Val {
         return root
     }
     
     left := lowestCommonAncestor(root.Left, p, q)
     right := lowestCommonAncestor(root.Right, p, q)
     
     if left != nil && right != nil {
         return root
     }
     
     if left == nil {
         return right
     }
     return left
}
```

Review:

1. 在MySQL中什么是Redo log

一个日志文件，更新操作的时候，先更新redo log,等系统空闲的时候将日志同步到磁盘当中。redo log是固定大小的，可以配置为一组4个文件，每个文件的大小是1GB,那么这块粉板总共就可以记录
4GB的操作。
当有一条记录需要更新的时候，InnoDB引擎就会先把记录写到redo log(粉板里面），并更新到内存，这个时候就算完成了。
《孔乙己》记账本有两种做法：

1.1 直接把账本翻出来，把这次赊的帐加上去或者扣掉

1.2 另一种做法是现在粉板上记下这次的帐，等打烊以后再把账本翻出来核算

粉板和账本配合的整个过程，其实就是MySQL里经常说到的WAL技术，WAL的全称是Write-Ahead Logging,它的关键点就是先写日志，再写磁盘，就是先写粉板，等不忙的时候在写账本
有了Redo log，InnoDB就可以保证即使数据库发生异常重启，之前提交的记录都不会丢失，这个能力称为crash-safe.

2. 什么是Bin log

bin log 是归档日志，是在Server 层的
                                       
3. redo log 和 bin log 有哪些不同？

   3.1 redo log 是InnoDB引擎特有的，binlog 是MySQL的Server 层实现的，所有引擎都可以使用
   
   3.2 redo log 物理日志，记录的是，在某个数据页上做了什么修改，binlog 是逻辑日志，记录的是这个语句的原始逻辑
   
   3.3 redo log 是循环写的，空间固定会用完，bin log 是可以追加写入的，追加写是指binlog 文件写到一定大小会切换到下一个，并不会覆盖以前的日志
                                       
3. 什么是两阶段提交？
redo log prepare
bin log
redo log commmit

Tips:
1. 单元测试很重要，但是为什么写单元测试更重要，要写可测试的代码

Share:
由MySQL 的Explain 看闭环 看交付
https://www.cnblogs.com/zhangpengfei5945/p/13300720.html
