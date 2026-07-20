class Solution {
public:
    void sortColors(vector<int>& nums) {
        int zeros=0, ones=0, twos=0;
        for(int i=0; i<nums.size(); i++){
            if(nums[i]==0) zeros++;
            else if(nums[i]==1) ones++;
            else twos++;
        }

        int i=0;
        while(zeros>0){
            nums[i]=0;
            zeros--;
            i++;
        }

        while(ones>0){
            nums[i]=1;
            ones--;
            i++;
        }

        while(twos>0){
            nums[i]=2;
            twos--;
            i++;
        }
    
    }
};