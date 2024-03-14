const int N = 2010;
//考虑拓扑排序的思想
class Solution {
private:
    int cnt[N];
    vector<int> v[N];
    int num=0;
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        for (int i=0; i<prerequisites.size(); i++)
        {
            int x,y;
            x=prerequisites[i][0],y=prerequisites[i][1];
            v[y].push_back(x);
            cnt[x]++;
        }
        queue<int> q;
        for (int i=0; i<numCourses; i++) if (!cnt[i]) q.push(i);
        while (q.size())
        {
            num++;
            int t=q.front();
            q.pop();
            for (int i=0; i<v[t].size(); i++)
            {
                if (--cnt[v[t][i]] == 0) q.push(v[t][i]);
            }
        }
        if (num == numCourses) return 1;
        else return 0;
    }
};