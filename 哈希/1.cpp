class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int len=nums.size();
        unordered_map<int,int> hash;
        for (int i=0; i<len; i++)
        {
//        	遍历一次可以降低时间复杂度
            auto it=hash.find(target-nums[i]);
//            vector<int>可以直接用{}输出，如果没有找到和hash.end()匹配
            if (it != hash.end()) return {it->second,i};
            else hash[nums[i]]=i;
        }
        return {};
    }
};