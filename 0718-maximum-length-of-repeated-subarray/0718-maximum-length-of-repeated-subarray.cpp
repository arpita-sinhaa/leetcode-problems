class Solution {
public:
vector<vector<int>> dp;

    int solve(int i1, int i2, vector<int>& nums1, vector<int>& nums2){
        if(i1>=nums1.size() || i2>=nums2.size()) return 0;

        if(dp[i1][i2]!= -1) return dp[i1][i2];

        if(nums1[i1]==nums2[i2]){ //match
            return dp[i1][i2]= 1 + solve(i1+1, i2+1, nums1, nums2);
        }
        else return dp[i1][i2]=0; //not match
    }

    int findLength(vector<int>& nums1, vector<int>& nums2) {
        dp.assign(nums1.size(), vector<int> (nums2.size(), -1));

        int ans=0;

        for(int i=0; i<nums1.size(); i++){
            for(int j=0; j<nums2.size(); j++){
                ans= max(ans, solve(i, j, nums1, nums2));
            }
        }
        return ans;
    }
};