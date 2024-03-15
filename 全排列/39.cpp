class Solution {
private:
    vector<vector<int>> ans;
    vector<int> v;
    void dfs(vector<int>& candidates,vector<int> v,int target,int pos,int sum)
    {
        if (sum == target)
        {
            ans.push_back(v);
            return;
        }
        if (pos == candidates.size()) return;
//        排除相同元素
        if (pos && candidates[pos] == candidates[pos-1]) dfs(candidates,v,target,pos+1,sum);
        while (sum <= target)
        {
            dfs(candidates,v,target,pos+1,sum);
            v.push_back(candidates[pos]);
            sum+=candidates[pos];
        }
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        dfs(candidates,v,target,0,0);
        return ans;        
    }
};