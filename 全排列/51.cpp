class Solution {
private:
    vector<vector<string>> ans;
    unordered_set<int> col,col1,col2;
    vector<int> queues;
    vector<string> now;
    int n;
    void dfs(int u)
    {
        if (u == n)
        {
            vector<string> v=Get();
            ans.push_back(v);
            return;
        }
        for (int i=0; i<n; i++)
        {
            if (col.find(i) != col.end()) continue;
            if (col1.find(i+u) != col1.end()) continue;
            if (col2.find(u-i) != col2.end()) continue;
            queues[u]=i;
            col.insert(i);
            col1.insert(i+u);
            col2.insert(u-i);
            dfs(u+1);
            col.erase(i);
            col1.erase(i+u);
            col2.erase(u-i);
        }
    }

    vector<string> Get()
    {
        now.clear();
        for (int i=0; i<n; i++)
        {
//        	string赋初值
            string t=string(n,'.');
            t[queues[i]]='Q';
            now.push_back(t);
        }
        return now;
    }
public:
    vector<vector<string>> solveNQueens(int n) {
        this->n=n;
        queues=vector<int>(n,0);
        dfs(0);
        return ans;
    }
};