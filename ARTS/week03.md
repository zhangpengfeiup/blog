Algorithm:
LeetCode 1465
```
class Solution {
public:
    int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts) {
        horizontalCuts.push_back(0);
        horizontalCuts.push_back(h);
        verticalCuts.push_back(0);
        verticalCuts.push_back(w);
        sort(horizontalCuts.begin(), horizontalCuts.end());
        sort(verticalCuts.begin(), verticalCuts.end());
        long long hMax = 0;
        long long wMax = 0;
        int i = 0;
        int j = 1;
        
        while (j < horizontalCuts.size()) {
            if (horizontalCuts[j] - horizontalCuts[i] > hMax) {
                hMax = horizontalCuts[j]-horizontalCuts[i];
            }
            i++;
            j++;
        }
         i = 0;
         j = 1;
        while (j < verticalCuts.size()) {
            if (verticalCuts[j] - verticalCuts[i] > wMax) {
                wMax = verticalCuts[j] - verticalCuts[i];
            }
            i++;
            j++;
        }
        long long mod = (1e9 + 7);
        long long ret = hMax * wMax;
        return ret % mod;
    }
};
```

Review:


Tips:

SQL: sql 起别名的时候要有select 语句进行操作，如果没有select，那么你起的别名有什么意义呢？

MVP:小范围先实验，然后现实情况会给我们反馈

躬身入局:只有参与进去和亲身体验你才有更多的感受，在外面看是感受不到的，要去进入到漩涡中心

Share:
https://www.cnblogs.com/zhangpengfei5945/
