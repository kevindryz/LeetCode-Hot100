class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int len=nums.size();
        int pos=nums.size()-1-1;
        while (pos >= 0 && nums[pos] >= nums[pos+1]) pos--;
        if (pos >= 0)
        {
            int r=len-1;
            for (int i=r; i>=pos; i--)
            {
                if (nums[i] > nums[pos])
                {
                    swap(nums[i],nums[pos]);
                    break;
                }
            }
        }
//        直接用reverse进行反转操作
        reverse(nums.begin()+pos+1,nums.end());
    }
};