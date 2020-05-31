#### Algorithm:
二叉树的前序遍历

```
 if (!root) {
            return {};
        }
        
        vector<int> res;
        stack<TreeNode*>  s{{root}};
        
        while (!s.empty()) {
            TreeNode *t = s.top();s.pop();
            res.push_back(t->val);
            
            if (t->right) {
                s.push(t->right);
            }
            
            if (t->left) {
                s.push(t->left);
            }
        }
        
        return res;
    }
```

上面的方式可能更加容易想出来，下面这个代码更加的通用

```
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        
        stack<TreeNode*> st;
        TreeNode *p = root;
        
        while (!st.empty() || p) {
            if (p) {
                st.push(p);
                res.push_back(p->val);
                p = p->left;
            }else {
                p = st.top();st.pop();
                p = p->right;
            }
        }
        return res;
    }
};
```
#### Review:

#### tips:
每次提交的代码进行小，就是改动和修改一个功能，方便设计，方便改动，方便测试
需要也是如是，将需求拆分到一个一个比较小的粒度，更加有利于排期和开发


#### Share:
https://www.cnblogs.com/zhangpengfei5945/p/12982382.html
