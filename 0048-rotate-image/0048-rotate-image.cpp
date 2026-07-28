class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n= matrix.size();
        vector<vector<int>> ans(n, vector<int>(n));

        int col=n-1;
        for(int i=0; i<n; i++){
            int row=0;
            for(int j=0; j<n; j++){
                ans[row][col]=matrix[i][j];
                row++;
            }
            col--;
        }

        matrix=ans;
    }
};