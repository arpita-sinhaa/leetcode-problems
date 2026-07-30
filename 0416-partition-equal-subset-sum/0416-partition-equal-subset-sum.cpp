class Solution {
public:
vector<vector<int>> dp;

    bool solve(int i, vector<int>& nums, int target){

        if(i>nums.size()-1) return false;

        if(target==0) return true;

        if(dp[i][target]!=-1) return dp[i][target];

        bool notpick= solve(i+1, nums, target);
        bool pick=false;
        if(nums[i] <=target){
            pick= solve(i+1, nums, target-nums[i]);
        }

        return dp[i][target]=pick || notpick;
    }

    bool canPartition(vector<int>& nums) {
        int sum=0;
        for(int num:nums){
            sum+=num;
        }

        if(sum%2!=0) return false;

        dp.assign(nums.size(), vector<int>(sum/2+1, -1));

        return solve(0, nums, sum/2);
    }
};