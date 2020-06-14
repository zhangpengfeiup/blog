Algorithm:
LeetCode:1471
```
class Solution {
public:
    vector<int> getStrongest(vector<int>& arr, int k) {
        sort(arr.begin(), arr.end());
        int m = arr[(arr.size() - 1) / 2];
        int l = 0,r = arr.size() - 1;
        vector<int> ans;
        while (ans.size() < k) {
            if (abs(arr[l] - m) <= abs(arr[r] - m)) {
                ans.push_back(arr[r--]);
            }else {
                ans.push_back(arr[l++]);
            }
        }
        return ans;
    }
};
```
Review:

Tips:
光有想法是没有用的，你要有行动，只有动起来才能让想法照进现实，然后现实会给你反馈。
不要劝别人学习、健身、运动，有这个时间不如多花时间想想怎么劝自己行动起来，多花一点时间学习、运动、健身。

Share:
记录自己的一些思考：https://www.cnblogs.com/zhangpengfei5945/p/13093769.html
