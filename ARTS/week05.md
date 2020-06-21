Algorithm:
```
/*
    前序遍历
    Go中是如何构建栈这个数据结构呢
    什么时候将元素放入到结果集中
    什么时候将元素执行右节点
 */
func preorderTraversal(root *TreeNode) []int {
    if root == nil {
        return nil
    }
    
    // 定义返回数组，定义栈结构
    result := make([]int, 0)
    stack := make([]*TreeNode, 0)
    
    // 循环条件，元素是否为空或者栈中元素大于0
    for root != nil || len(stack) > 0 {
        for root != nil {
            result = append(result, root.Val)
            stack = append(stack, root)
            root = root.Left
        }
        node := stack[len(stack) - 1]
        // pop
        stack = stack[:len(stack) - 1]
        root = node.Right
    }
    return result
}
```

```
/*
 思考：中序遍历，返回结果如何存放？
 如何使用栈进行遍历
 思路：将节点的Left都放入到栈中，如果Left为空的时候，将栈中最后一个节点弹出，将该节点的值写入到返回数组中，将该节点的右子树放入到栈中
 */
func inorderTraversal(root *TreeNode) []int {
    result := make([]int, 0)
    if root == nil {
        return result
    }
    
    stack := make([]*TreeNode, 0)
    for len(stack) > 0 || root != nil {
        for root != nil {
            // 将node放入到stack中
            stack = append(stack, root);
            root = root.Left;
        }
        // pop
        node := stack[len(stack) - 1]
        stack = stack[:len(stack) - 1]
        result = append(result, node.Val)
        root = node.Right
    }
    return result
}
```

Review:

https://xie.infoq.cn/article/9c9bdc7cba67bc47f8f5686c3
1. 深入思考，总结沉淀
2. 主动承担，及时交流反馈，有owner 意识
3. 建立信任、超出预期、体系化思考、系统化建设、提升自己的软素质能力
Tips:

写可测试的代码，from 安装Mariadb ColumnStore 的时候有测试脚本检查环境是否正确，可以想到，我们日常开发的时候也想去写可测试的代码
思考的过程和结果同样重要，因为过程正确，结果才有价值和意义
培养自己的微习惯

Share:

[多多行动，Action And Think Not Thinking Thinking But Not Action](https://www.cnblogs.com/zhangpengfei5945/p/13171882.html)

现阶段不要想特别多，多动手，不要给自己找困难，很多问题并没有自己想多那么困难，可能只是自己把困难放大了。

躬身入局

算法和数据结构：基本上都是给你一个问题，让你想用什么数据结构解决，堆（大顶堆、小顶堆）、树（平衡二叉树、二叉搜索树、红黑树等等）和链表（单向链表、双向链表、循环链表）多看看
