class Solution {
public:
    string smallestSubsequence(string s) {
        vector<int> last_index(26);
        for(int i=0; i<s.size(); i++){
            last_index[s[i]-'a']=i;
        }

        string ans;
        vector<int> vis(26, 0);
        for(int i=0; i<s.size(); i++){

            if(vis[s[i]-'a']==1) continue;

            //remove char from back if it > curr char and appears againnn
            while(!ans.empty() && ans.back() > s[i] && last_index[ans.back()-'a']>i){
                vis[ans.back()-'a']=0;
                ans.pop_back();
            }

            ans+=s[i];
            vis[s[i]-'a']=1;
        }
        return ans;
    }
};