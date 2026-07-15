class Solution {
public:
    void dfs(int row, int col, vector<vector<int>>& grid, vector<vector<int>>& vis, int &count, bool& border){
        int n=grid.size();
        int m=grid[0].size();

        vis[row][col]=1;
        count++;

        if(row==0 || row==n-1 || col==0 || col==m-1){
            border=true;
        }

        int delr[]={1,0,-1,0};
        int delc[]={0,1,0,-1};

        for(int k=0; k<4; k++){
            int nr=delr[k]+row;
            int nc=delc[k]+col;

            if(nr>=0 && nr<n && nc>=0 &&nc<m && grid[nr][nc]==1 && vis[nr][nc]==0){
                dfs(nr,nc, grid, vis, count, border);
            }
        }
    }

    int numEnclaves(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m,0));

        int ans=0;
        //bool border=false;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j]==1 && vis[i][j]==0){
                    //reset count & border check for each cell
                    int count=0;
                    bool border= false;
                    dfs(i,j,grid, vis, count, border);

                    //add all cells from this boundary if not touching border
                    if(border==false) ans+= count;
                }
            }
        }
        return ans;
    }
};