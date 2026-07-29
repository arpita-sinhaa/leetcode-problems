class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxprod=nums[0];
        for(int i=0; i<nums.size(); i++){
            int prod=1;
            for(int j=i; j<nums.size(); j++){
                prod*=nums[j];
                maxprod=max(maxprod, prod);
            }
        }
        return maxprod;
    }
};