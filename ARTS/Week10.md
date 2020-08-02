Algorithm:
Divide & Conquer

balanced-binary-tree: leetcode 110

自顶向下：
```
/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func height(root *TreeNode) float64 {
    if root == nil {
        return -1
    }
    leftHeight := height(root.Left)
    rightHeight := height(root.Right)
    return 1 + math.Max(float64(leftHeight),float64(rightHeight))
}
func isBalanced(root *TreeNode) bool {
    if root == nil {
        return true
    }
    
    leftHeight := height(root.Left)
    rightHeight := height(root.Right)
    return math.Abs(leftHeight - rightHeight) < 2 && isBalanced(root.Left) && isBalanced(root.Right)
}
```

自底向上：
```
func maxDepth(root *TreeNode) int {
    if root == nil {
        return 0
    }
    
    left := maxDepth(root.Left)
    right := maxDepth(root.Right)
    if left == -1 || right == -1 || left - right > 1 || right - left > 1 {
        return -1
    }
    if left > right {
        return left + 1
    }
    return right + 1
}
func isBalanced(root *TreeNode) bool {
    if maxDepth(root) == -1 {
        return false
    }
    return true
}
```
