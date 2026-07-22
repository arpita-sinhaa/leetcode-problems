class Solution {
public:
    string frequencySort(string s) {
        vector<pair<int, int>> freq(123);
        for(char ch:s){
            freq[ch].first=ch;
            freq[ch].second++;
        }

        auto cmp= [&] (pair<char, int>p1, pair<char, int>p2){
            return p1.second>p2.second;
        };

        sort(freq.begin(), freq.end(), cmp);

        string ans="";
        for(auto it:freq){
            if(it.second!=0){
                for(int i=0; i<it.second; i++){
                    ans.push_back(it.first);
                }
            }
        }
        return ans;
    }
};