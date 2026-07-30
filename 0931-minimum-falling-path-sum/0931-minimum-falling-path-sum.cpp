class Solution {
public:
vector<vector<int>> dp;

    int solve(int i, int j, vector<vector<int>>& matrix){

        int n=matrix.size();

        if(j<0 || j>n-1) return INT_MAX/2;

        if(i==n-1) return matrix[i][j];

        if(dp[i][j]!= INT_MAX) return dp[i][j];

        int down= matrix[i][j] + solve(i+1, j, matrix);
        int ldiag= matrix[i][j] + solve(i+1, j-1, matrix);
        int rdiag= matrix[i][j] + solve(i+1, j+1, matrix);

        return dp[i][j]= min({down, ldiag, rdiag});
    }

    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n=matrix.size();

        dp.assign(n, vector<int>(n, INT_MAX));

        int minsum=INT_MAX;
        for(int j=0; j<n; j++){
            minsum= min(minsum, solve(0, j, matrix));
        }
        return minsum;
    }
};