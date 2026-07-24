class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n=grid.size();
        if(grid[0][0]==1 || grid[n-1][n-1]==1) return -1;

        queue<pair<int,int>> q;
        q.push({0,0});
        grid[0][0]=1; //marking vis, no need of sep vis matrix

        int delr[]={1, 1, 0, -1, -1, -1, 0, 1};
        int delc[]={0, 1, 1, 1, 0, -1, -1, -1};

        int dist=1;
        while(!q.empty()){
            int levelsz=q.size();

            for(int i=0; i<levelsz; i++){
                int row=q.front().first;
                int col=q.front().second;
                q.pop();

                //destination reached
                if(row == n-1 && col == n-1) return dist;

                for(int k=0; k<8; k++){
                    int nr= delr[k]+row;
                    int nc= delc[k]+col;

                    if(nr>=0 && nr<n && nc>=0 && nc<n && grid[nr][nc]==0){
                        q.push({nr, nc});
                        grid[nr][nc]=1;
                    }
                }
            }
            dist++; //inc after each level
        }
        return -1;
    }
};