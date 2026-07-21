class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        //count ones
        //store conseutive count of 0 blocks
        //ans- max pair sum of 0 blocks + no. of ones

        int n=s.size();
        int ones=0;
        for(int num:s){
            if(num=='1') ones++;
        }

        vector<int> zeroBlocks;
        int i=0;
        while(i<n){
            if(s[i]=='0'){
                int start=i;
                while(i<n && s[i]=='0'){
                    i++;
                }
                zeroBlocks.push_back(i-start);
            }
            else i++;
        }

        int maxsum=0;
        for(int i=1; i<zeroBlocks.size(); i++){
            maxsum= max(maxsum, zeroBlocks[i-1]+zeroBlocks[i]);
        }
        return maxsum+ones;
    }
};