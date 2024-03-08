class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int l,r;
        l=r=0;
        int len=num.size();
//        类似于从左到右遍历，找非0点，l其实就是一个计数器cnt
        while (r < len)
        {
            if (nums[r])
            {
                swap(nums[r],nums[l]);
                l++;
            }
            r++;
        }

    }
};