class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int len=nums.size();
//        懒得想了，用了哈希，时空间复杂度都是O(N)
        unordered_map<int,int> hash;
        for (auto t : nums)
        {
            hash[t]++;
            if (hash[t] > len/2) return t;
        }
        return 0;
    }
};