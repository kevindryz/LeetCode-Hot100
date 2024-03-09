class Solution {
public:
    void sortColors(vector<int>& nums) {
        int len=nums.size();
        int l=0,r=len-1;
        int pos=0;
//        确定区间后排序
        while (pos <= r)
        {
            if (nums[pos] == 0)
            {
                swap(nums[pos],nums[l]);
                l++;
                pos++;
            }
            else if (nums[pos] == 1)
            {
                pos++;
            }
            else
            {
                swap(nums[pos],nums[r]);
                r--;
            }
        }
        return;
    }
};