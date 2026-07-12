class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n= grid.size();
        int m= grid[0].size();

        vector<vector<int>> vis(n, vector<int>(m, 0));
        queue<pair<int, int>> q;
        int fresh= 0;

        for (int i=0; i<n; i++) {
            for (int j= 0; j< m; j++) {
                if (grid[i][j]== 2 && vis[i][j]== 0) {
                    q.push({i,j});
                    vis[i][j]= 1;
                } else if (grid[i][j]== 1) fresh++;
            }
        }

        int delr[]= {1, 0, -1, 0};
        int delc[]= {0, 1, 0, -1};
        int mins= 0;
        while (!q.empty() && fresh>0) {
            int level = q.size();
            mins++;

            for (int i= 0; i< level; i++) {
                int row= q.front().first;
                int col= q.front().second;
                q.pop();

                for (int k= 0; k< 4; k++) {
                    int nr = delr[k] +row;
                    int nc = delc[k] +col;

                    if (nr >= 0 && nr< n && nc >= 0 && nc< m &&
                        grid[nr][nc]== 1 && vis[nr][nc]== 0) {
                        q.push({nr, nc});
                        vis[nr][nc] = 1;
                        fresh--;
                    }
                }
            }
        }
        if (fresh > 0) return -1;
        else return mins;
    }
};