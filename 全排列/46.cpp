class Solution {
private:
    int flag[7];
    vector<int> v;
    vector<vector<int>> ans;
    void dfs(vector<int>& nums,int pos)
    {
        if (nums.size() == pos)
        {
            ans.push_back(v);
        }
        for (int i=0; i<nums.size(); i++)
        {
            if (flag[i]) continue;
            v.push_back(nums[i]);
            flag[i]=1;
            dfs(nums,pos+1);
//            用pop_back()弹出末尾元素
            v.pop_back();
            flag[i]=0;
        }

    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        dfs(nums,0);
        return ans;
    }
};