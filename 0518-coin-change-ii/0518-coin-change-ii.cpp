class Solution {
public:
vector<vector<int>> dp;
    int solve(int i, vector<int>& coins, int amount){
        if(i>coins.size()-1) return 0;

        if(amount==0) return 1;

        if(dp[i][amount]!=-1) return dp[i][amount];

        int notpick=solve(i+1, coins, amount);
        int pick=0;
        if(coins[i]<=amount){
            pick= solve(i, coins, amount-coins[i]);
        }

        return dp[i][amount]= pick+ notpick;
    }

    int change(int amount, vector<int>& coins) {
        dp.assign(coins.size(), vector<int>(amount+1, -1));

        return solve(0, coins, amount);
    }
};