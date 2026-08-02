class Solution {
public:
vector<vector<int>> dp;
    int solve(int i1, int i2, string& s1, string& s2){
        if(i1>= s1.size() || i2>=s2.size()) return 0;

        if(dp[i1][i2]!=-1) return dp[i1][i2];

        int match=0;
        if(s1[i1]==s2[i2]){
            match= 1 + solve(i1+1, i2+1, s1, s2);
        }
        
        int notmatch= 0 + max(solve(i1+1, i2, s1, s2), solve(i1, i2+1, s1, s2));

        return dp[i1][i2]= max(match, notmatch);
    }

    int longestPalindromeSubseq(string s) {
        string s1=s;
        //string s2= reverse(s.begin(), s.end()); dont do this, reverse op. returns void
        string s2=s;
        reverse(s2.begin(), s2.end());

        dp.assign(s1.size(), vector<int>(s2.size(), -1));

        return solve(0,0, s1, s2); 
    }
};

 