class Solution {
public:
vector<vector<int>> dp;
    int solve(int i1, int i2, string& text1, string& text2){
        if(i1>=text1.size() || i2>=text2.size()) return 0;

        if(dp[i1][i2]!=-1) return dp[i1][i2];

        int match=0;
        if(text1[i1]==text2[i2]){
            match= 1 + solve(i1+1, i2+1, text1, text2);
        }
        int notmatch= 0 + max(solve(i1+1, i2, text1, text2), solve(i1, i2+1, text1, text2));

        return dp[i1][i2]= max(match, notmatch);
    }

    int longestCommonSubsequence(string text1, string text2) {
        dp.assign(text1.size()+1, vector<int>(text2.size()+1, -1));
        return solve(0,0, text1, text2);
    }
};