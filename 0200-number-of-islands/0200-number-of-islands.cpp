class Solution {
public:
    void dfs(int row, int col, vector<vector<char>>& grid, vector<vector<int>>& vis){
        int n=grid.size();
        int m=grid[0].size();

        vis[row][col]=1;

        int delr[]= {1, 0, -1, 0};
        int delc[]= {0, 1, 0, -1};

        for(int k=0; k<4; k++){
            int nr=delr[k]+row;
            int nc=delc[k]+col;

            if(nr>=0 && nr<n && nc>=0 && nc<m && grid[nr][nc]=='1' && vis[nr][nc]==0) dfs(nr,nc, grid, vis);
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size();
        int m=grid[0].size();

        vector<vector<int>> vis(n, vector<int>(m,0));

        int count=0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j]=='1' && vis[i][j]==0){
                    dfs(i,j,grid,vis);
                    count++;
                }
            }
        }
        return count;
    }
};