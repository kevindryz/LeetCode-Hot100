class Solution {
private:
    string s[10];
    vector<string> ans;
    string now="";

    void init()
    {
        s[2]="abc";
        s[3]="def";
        s[4]="ghi";
        s[5]="jkl";
        s[6]="mno";
        s[7]="pqrs";
        s[8]="tuv";
        s[9]="wxyz";
    }

    void dfs(string digits,int pos)
    {
        if (digits.length() == pos)
        {
            ans.push_back(now);
            return;
        }
        string tem=s[digits[pos]-'0'];
        string pre=now;
        for (auto t : tem)
        {
            now+=t;
            dfs(digits,pos+1);
            now=pre;
        }
    }
public:
    vector<string> letterCombinations(string digits) {
        init();
        if (digits.length()) dfs(digits,0);
        return ans;
    }
};