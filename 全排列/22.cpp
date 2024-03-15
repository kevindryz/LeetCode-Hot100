class Solution {
private:
    int num;
    vector<string> ans;
    void dfs(string now,int cnt,int left){
        if (cnt == num*2)
        {
            ans.push_back(now);
            return;
        }
        if (left == num)
        {
            now+=')';
            dfs(now,cnt+1,left);
        }
        else
        {
            dfs(now+'(',cnt+1,left+1);
            if (left > (cnt-left)) dfs(now+')',cnt+1,left);
        }
    }
public:
    vector<string> generateParenthesis(int n) {
        string now="(";
        this->num=n;
        dfs(now,1,1);
        return ans;
    }
};