class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int len=nums.size();
        int l=0,r=len-1;
//        用二分解，但是时间复杂度比较大
        while (l < r)
        {
            int mid=l+r>>1;
            int cnt=0;
            for (int i=0; i<len; i++)
            {
                if (nums[i] <= mid) cnt++;
            }
            if (cnt <= mid) l=mid+1;
            else
            {
                r=mid;
            }
        }
        return l;

    }
};