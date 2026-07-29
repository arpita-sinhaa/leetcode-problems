class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n=nums.size();
        int prefixprod=1, suffixprod=1;
        int maxprod=INT_MIN;

        for(int i=0; i<n; i++){
            if(prefixprod==0) prefixprod=1;
            if(suffixprod==0) suffixprod=1;

            prefixprod*= nums[i];
            suffixprod*=nums[n-i-1];

            maxprod=max(maxprod, max(prefixprod, suffixprod));
        }
        return maxprod;
    }
};