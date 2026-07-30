class Solution {
public:
vector<vector<int>> dp;

    int solve(int i, int j, vector<vector<int>>& triangle){
        int n=triangle.size();

        //reached last row
        if(i==n-1) return triangle[i][j];

        if(dp[i][j]!=INT_MAX) return dp[i][j];

        int down= triangle[i][j] + solve(i+1, j, triangle);
        int diagdown= triangle[i][j] + solve(i+1, j+1, triangle);

        return dp[i][j]= min(down, diagdown);
    }

    int minimumTotal(vector<vector<int>>& triangle) {
        int n=triangle.size();

        dp.assign(n, vector<int>(n, INT_MAX));

        return solve(0,0,triangle);
    }
};