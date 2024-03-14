typedef pair<int,int> PII;
class Solution {
private:
    int dx[4]={0,1,0,-1};
    int dy[4]={1,0,-1,0};
    int f[15][15];
    queue<PII> q;
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int cnt,sum,step;
        cnt=sum=step=0;
        int n,m;
        m=grid.size(),n=grid[0].size();
        for (int i=0; i<m; i++)
        {
            for (int j=0; j<n; j++)
            {
                if (grid[i][j] == 1) cnt++;
                else if (grid[i][j] == 2)
                {
                    cnt++;
                    sum++;
                    q.push({i,j});
                    f[i][j]=1;
                }
            }
        }
        if (sum == cnt) return 0;
//        bfs
        while (q.size())
        {
            int len=q.size();
            step++;
            while (len--)
            {
                auto t=q.front();
                q.pop();
                int x=t.first,y=t.second;
                for (int i=0; i<4; i++)
                {
                    int xx=x+dx[i],yy=y+dy[i];
                    if (xx < 0 || xx >= m || yy < 0 || yy >= n || grid[xx][yy] != 1) continue;
                    grid[xx][yy]=2;
                    f[xx][yy]=1;
                    q.push({xx,yy});
                    sum++;
                }
            }
        }
        if (sum == cnt) return step-1;
        else return -1;
    }
};