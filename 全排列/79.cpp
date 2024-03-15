class Solution {
private:
    int m,n;
    int flag[7][7];
    int ans=0;
    int dx[4]={0,1,0,-1};
    int dy[4]={1,0,-1,0};
    string word;
    vector<vector<char>> board;
    void dfs(int x,int y,int pos)
    {
        if (pos == word.length())
        {
            ans=1;
            return;
        }
        if (ans) return;
        for (int i=0; i<4; i++)
        {
            int xx=x+dx[i],yy=y+dy[i];
            if (xx < 0 || xx >= m || yy < 0 || yy >= n) continue;
            if (flag[xx][yy]) continue;
            if (board[xx][yy] == word[pos])
            {
                flag[xx][yy]=1;
                dfs(xx,yy,pos+1);
                flag[xx][yy]=0;
            }
        }
    }
public:
    bool exist(vector<vector<char>>& board, string word) {
        m=board.size(),n=board[0].size();
        this->board=board;
        this->word=word;
        for (int i=0; i<m; i++)
        {
            for (int j=0; j<n; j++)
            {
                if (board[i][j] == word[0])
                {
                    memset(flag,0,sizeof flag);
                    flag[i][j]=1;
                    dfs(i,j,1);
                    if (ans) return 1;
                }
            }
        }
        return 0;

    }
};