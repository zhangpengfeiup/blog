Algorithm:
DFS: Permutations:
三哥盒子，每个盒子，你可以发东西，也可以不放
```
func dfs(nums []int,pos int, list []int,visited []bool,result *[][]int) {
     // terminator
     if pos == len(nums) {
         ans := make([]int, len(list))
         copy(ans, list)
         *result = append(*result, ans)
         return
     }
     for i := 0;i < len(nums);i++ {
         if visited[i] {
             continue;
         }
         // process current logic
         list = append(list, nums[i])
         visited[i] = true
         // drill down
         dfs(nums, pos + 1, list, visited, result)
    
         list = list[0:len(list) - 1]
         visited[i] = false
     }   
}
func permute(nums []int) [][]int {
     result := make([][]int ,0)
     list := make([]int, 0)
     visited := make([]bool, len(nums))
     pos := 0
    dfs(nums, pos, list, visited, &result)
    return result
}
```
Review:

编程语言中语法是固定的，使用语法写出的优秀的项目是灵活的，是思想的，是有灵魂的

https://lutaonan.com/blog/my-coding-road

Tips:

睡好觉，尽可能不熬夜

做决定的时候让自己冷静下来

你要知道你要的是什么

Share:

[有意识地培养自己的结构化思维，清晰合适恰当地表达出自己的想法](https://www.cnblogs.com/zhangpengfei5945/p/13408101.html)
