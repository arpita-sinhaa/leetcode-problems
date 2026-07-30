class Solution {
public:
vector<vector<int>>dp;

    int solve(int i, int j, vector<vector<int>>& grid){
        int n=grid.size();
        int m=grid[0].size();

        if(i>n-1 || j>m-1) return INT_MAX/2;

        if(i==n-1 && j==m-1) return grid[i][j];

        if(dp[i][j]!=-1) return dp[i][j];

        int down= grid[i][j] + solve(i+1, j, grid);
        int right= grid[i][j] + solve(i, j+1, grid);

        return dp[i][j]= min(down, right);
    }

    int minPathSum(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        dp.assign(n, vector<int>(m,-1));

        return solve(0,0,grid);
    }
};