class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n= mat.size();
        int m= mat[0].size();
        vector<vector<int>> ans(n, vector<int>(m,0));
        vector<vector<int>> vis(n, vector<int>(m,0));
        queue<pair<pair<int,int>,int>>q; //row, col, dist

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(mat[i][j]==0){
                    q.push({{i,j},0});
                    vis[i][j]=1;
                }
            }
        }

        int delr[]={0,+1,0,-1};
        int delc[]={+1,0,-1,0};

        while(!q.empty()){
            int row= q.front().first.first;
            int col= q.front().first.second;
            int dist= q.front().second;
            q.pop();

            //updating the ans matrix
            ans[row][col]=dist;

            for(int k=0; k<4; k++){
                int nr= delr[k]+row;
                int nc= delc[k]+col;

                if(nr>=0 && nr<n && nc>=0 && nc<m && vis[nr][nc]==0 && mat[nr][nc]==1){
                    q.push({{nr, nc}, dist+1});
                    vis[nr][nc]=1;
                }
            }
        }
        return ans;
    }
};