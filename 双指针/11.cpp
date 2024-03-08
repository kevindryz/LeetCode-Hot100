class Solution {
public:
    int maxArea(vector<int>& height) {
        int len=height.size();
        int l=0,r=len-1;
        int res=0;
//        只有短边向内才有可能使面积增大，就是要找出最大面积
        while (l < r)
        {
            if (height[l] <= height[r])
            {
                res=max(res,(r-l)*height[l]);
                l++;
            }
            else
            {
                res=max(res,(r-l)*height[r]);
                r--;
            }
        }
        return res;
    }
};