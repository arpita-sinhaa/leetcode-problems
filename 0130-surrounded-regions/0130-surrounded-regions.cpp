class Solution {
public:
    void dfs(int row, int col, vector<vector<char>>& board,vector<vector<int>>& vis, vector<pair<int,int>>& cells, bool& border){
        int n=board.size();
        int m=board[0].size();

        vis[row][col]=1;
        cells.push_back({row,col});

        //boundary check
        if(row==0 || row==n-1 || col==0 || col==m-1) border=true;

        int dr[]={1, 0, -1, 0};
        int dc[]={0, 1, 0,-1};

        for(int k=0; k<4; k++){
            int nr=dr[k]+row;
            int nc=dc[k]+col;

            if(nr>=0 && nr<n && nc>=0 && nc<m && vis[nr][nc]==0 && board[nr][nc]=='O'){
                dfs(nr, nc, board, vis, cells, border);
            }
        }
    }

    void solve(vector<vector<char>>& board) {
        int n=board.size();
        int m=board[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(vis[i][j]==0 && board[i][j]=='O'){
                    vector<pair<int,int>> cells;
                    bool border=false;
                    dfs(i, j, board, vis, cells, border);

                    if(border==false){
                        for(auto it: cells){
                            board[it.first][it.second]='X';
                        }
                    }
                }
            }
        }
    }
};