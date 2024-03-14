const int N = 310;
class Solution {
private:
    int dx[4]={0,1,0,-1};
    int dy[4]={1,0,-1,0};
    int f[N][N];
    int cnt=0;
    int m,n;
    vector<vector<char>> grid;
    void dfs(int x,int y)
    {
        f[x][y]=1;
        for (int i=0; i<4; i++)
        {
            int xx=x+dx[i],yy=y+dy[i];
            if (xx < 0 || xx >= m || yy < 0 || yy >= n || grid[xx][yy] == '0' || f[xx][yy]) continue;
            dfs(xx,yy);
        }
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        this->m=grid.size();
        this->n=grid[0].size();
        this->grid=grid;
        for (int i=0; i<m; i++)
        {
            for (int j=0; j<n; j++)
            {
                if (f[i][j] || grid[i][j] == '0') continue;
                dfs(i,j);
                this->cnt++;
            }
        }
        return cnt;
    }
};