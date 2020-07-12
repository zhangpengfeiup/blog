Algorithm:
路径总和II:

```
var res[][]int
func pathSum(root *TreeNode, sum int) [][]int {
    res = [][]int{}
    dfs(root,sum,[]int{})
    return res
}
func dfs(root *TreeNode,sum int,stack []int) {
    if root == nil {
        return
    }
    stack = append(stack, root.Val)
    if root.Left == nil && root.Right == nil {
        if sum == root.Val {
            r := make([]int, len(stack))
            copy(r, stack)
            res = append(res, r)
        }
    }
    dfs(root.Left, sum - root.Val, stack)
    dfs(root.Right, sum - root.Val, stack)
}
```

Review:

[Linux 下删点日志也能搞死人](https://v2ex.com/t/687093)

下面为帖子中的评论感觉蛮好的，就写下来了
面试的时候面试官想要考察哪些能力？
1. 技术能力：包括广度和深度，深度尤其重要，知其然还要知其所以然
2. 学习能力：对于不熟悉的领域，是怎了了解到掌握的，这个过程中最能体现逻辑性
3. 性格特质：乐观/皮实/自省

Tips:

写可测试的代码
写可测试的模块
写可说清楚的功能
不要自己觉得，要可以验证
不要完美主义：just do it

Share:
