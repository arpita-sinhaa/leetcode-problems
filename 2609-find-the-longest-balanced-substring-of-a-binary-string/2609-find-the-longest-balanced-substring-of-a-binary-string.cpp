class Solution {
public:
    int findTheLongestBalancedSubstring(string s) {
        int zeros=0, ones=0, ans=0;
        for(int i=0; i<s.size(); i++){
            if(s[i]=='0'){
                if(i>0 && s[i-1]=='1'){
                    zeros=0;
                    ones=0;
                }
                zeros++;
            }
            else if(zeros>0){
                ones++;
                ans= max(ans, 2*min(zeros, ones));
            }
        }
        return ans;
    }
};