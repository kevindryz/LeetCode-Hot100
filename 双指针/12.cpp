class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        int len=nums.size();
//        排序后就可以根据大小进行双指针
        sort(nums.begin(),nums.end());
        for (int i=0; i<len; i++)
        {
            if (i && nums[i] == nums[i-1]) continue;
            int k=len-1;
            for (int j=i+1; j<len; j++)
            {
                if (nums[j] == nums[j-1] && j > i+1) continue;
                while (j < k && nums[j] + nums[k] + nums[i] > 0) k--;
                if (j == k) break;
                else if (nums[i] + nums[j] + nums[k] == 0) ans.push_back({nums[i],nums[j],nums[k]});
            }
        }
        return ans;
    }
};