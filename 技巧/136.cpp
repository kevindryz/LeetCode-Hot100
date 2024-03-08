class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int res=0;
//        位运算省空间复杂度，只需要一位
        for (auto t : nums) res^=t;
        return res;
    }
};