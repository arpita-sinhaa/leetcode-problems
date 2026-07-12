class Solution {
public:
    void dfs(int row, int col, vector<vector<int>>& image, int color, int initialcolor){
        int n=image.size();
        int m=image[0].size();

        image[row][col]=color;

        int delr[]={1, 0, -1, 0};
        int delc[]={0, 1, 0, -1};

        for(int k=0; k<4; k++){
            int nr= delr[k]+row;
            int nc=delc[k]+col;

            if(nr>=0 && nr<n && nc>=0 && nc<m && image[nr][nc]==initialcolor && image[nr][nc]!=color) dfs(nr, nc, image, color, initialcolor);
        }
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n=image.size();
        int m=image[0].size();

        int initialcolor= image[sr][sc];

        dfs(sr, sc, image, color, initialcolor);

        return image;
    }
};