class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        vector<int> temp(arr.begin(), arr.end());
        sort(temp.begin(), temp.end());

        unordered_map<int, int> mp; //val, rank
        int rank=1;

        for(int num : temp){
            if(mp.find(num)==mp.end()){
                mp[num]=rank;
                rank++;
            }
        }

        vector<int> ans(arr.size());
        for(int i=0; i<arr.size(); i++){
            ans[i]=mp[arr[i]];
        }
        
        return ans;
    }
};