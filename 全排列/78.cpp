class Solution {
private:
    vector<vector<int>> ans;
    vector<int> v;
    void dfs(vector<int>& nums,int pos)
    {
        if (nums.size() == pos)
        {
            ans.push_back(v);
            return;
        }
        dfs(nums,pos+1);
        v.push_back(nums[pos]);
        dfs(nums,pos+1);
        v.pop_back();
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        dfs(nums,0);
        return ans;
    }
};