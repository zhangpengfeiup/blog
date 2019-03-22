1. Abstract

2. Introduction

3. Go at Google

4. Pain points 痛点

当Go 发布的时候，一些人声称Go缺少被认为是现代语言的必要特征和方法。如果没有这些设施，Go怎么可能值得？我们的答案是：Go确实解决了使大规模软件开发变得困难的问题。这些问题包括:

slow builds 慢的编译
  
uncontrolled dependencies 不可控制的依赖
  
each programmer using a different subset of the language  每个程序员使用不同语言的子集

poor program understanding(code hard to read,poorly documented,and so on) 难以理解的程序(代码不容易阅读，文档记录不当，等等)

duplication of effort 重复劳动

cost of updates 更新费用

version skew 版本倾斜

difficulty of writing automatic tools 很难编写自动化工具

cross-language builds 跨语言构建

语言的各个特征无法解决这些问题. 需要更大的软件工程视图，在Go的设计中，我们试图关注这些问题的解决方案。

作为一个简单，自我包含的例子，考虑程序结构的代表性。一些观察者反对使用大括号的Go的C-like块结构，更喜欢使用空格作为缩进，更喜欢使用Ptyhon或Haskell风格的缩进空格. 然而，我们在跟踪由跨语言构建引起的构建和测试失败方面有丰富的经验，其中嵌入在另一种语言中的Ptyhon片段，例如通过SWIG调用，被周围代码缩进的变化巧妙和无形地破幻着。我们的定位就在这里，尽快缩小的空间对于小程序来说很好， 在大规模的情况下，它没有那么好，并且越大和混合的代码库，它引起的麻烦越大。最好为了安全性和可扩展性放弃便利性，所以Go有大括号包围的代码块。