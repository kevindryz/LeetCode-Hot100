class Solution {
public:
    int trap(vector<int>& height) {
        int len=height.size();
        stack<int> s;
//        注意局部变量要初始化为0
        int res=0;
        for (int i=0; i<len; i++)
        {
//        	每次计算一个矩形块的面积，当比前面一块长的时候算面积
            while (s.size() && height[s.top()] < height[i])
            {
                int tem=s.top();
                s.pop();
//                如果前面已经没有了，不构成矩形
                if (s.size() == 0) break;
//                前边界的位置
                int now=s.top();
//                选择短边
                int hmin=min(height[now],height[i]);
                res+=(i-now-1)*(hmin-height[tem]);
            }
            s.push(i);
        }
        return res;
    }
};