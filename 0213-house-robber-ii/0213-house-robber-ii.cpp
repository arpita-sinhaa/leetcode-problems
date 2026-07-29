class Solution {
public:
vector<int> dp;

    int solve(int i, int end, vector<int>& nums){
        if(i>end) return 0;

        if(dp[i]!=-1) return dp[i];

        int skip= solve(i+1, end, nums);
        int take= nums[i]+ solve(i+2, end, nums);

        return dp[i]= max(skip, take);
    }

    int rob(vector<int>& nums) {
        int n=nums.size();

        //imp base case
        if(n==1) return nums[0];

        //decalre for first option
        dp.assign(n, -1);
        int option1= solve(0, n-2, nums);

        //redeclare for 2nd option as same dp cant be used for boht calls
        dp.assign(n,-1);
        int option2= solve(1, n-1, nums);

        return max(option1, option2);
    }
};