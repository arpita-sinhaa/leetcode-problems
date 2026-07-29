class Solution {
public:
vector<int> dp;
    int solve(int i, vector<int>& nums){
        if(i>=nums.size()) return 0;

        if(dp[i]!=-1) return dp[i];

        int skip= solve(i+1, nums);
        int take= nums[i]+solve(i+2, nums);

        return dp[i]= max(skip, take);
    }

    int rob(vector<int>& nums) {
        dp.assign(nums.size(), -1);
        return max(solve(0, nums), solve(1, nums));
    }
};