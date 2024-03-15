class Solution {
private:
    vector<vector<string>> ans;
    vector<string> v;
    string s;
    int flag[20][20];

    void dfs(int u)
    {
        if (u == s.length())
        {
            ans.push_back(v);
            return;
        }
        for (int i=u; i<s.length(); i++)
        {
            if (check(u,i) == 1)
            {
                v.push_back(s.substr(u,i-u+1));
                dfs(i+1);
                v.pop_back();
            } 
        }
    }

//	1表示回文，0表示未检索，-1表示非回文
    int check(int l,int r)
    {
        if (flag[l][r]) return flag[l][r];
        if (l >= r) return 1;
        if (s[l] != s[r])
        {
            flag[l][r]=-1;
            return -1;
        }
        else
        {
            flag[l][r]=check(l+1,r-1);
            return flag[l][r];
        }
    }
public:
    vector<vector<string>> partition(string s) {
        this->s=s;
        dfs(0);
        return ans;
    }
};