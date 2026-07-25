class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n=heights.size();
        int m=heights[0].size();

        vector<vector<int>> dist(n, vector<int>(m,1e9));
        dist[0][0]=0;

        priority_queue<pair<int, pair<int,int>>, vector<pair<int, pair<int,int>>>, greater<pair<int, pair<int,int>>>> pq;
        pq.push({0,{0,0}});

        int delr[]={1,0,-1,0};
        int delc[]={0,1,0,-1};

        while(!pq.empty()){
            int diff=pq.top().first;
            int row=pq.top().second.first;
            int col=pq.top().second.second;
            pq.pop();

            if(row==n-1 && col==m-1) return diff;

            for(int k=0; k<4; k++){
                int nr=delr[k]+row;
                int nc=delc[k]+col;

                if(nr>=0 && nr<n &&nc>=0 && nc<m){
                    int newdiff= max(abs(heights[row][col]-heights[nr][nc]), diff);
                    if(newdiff < dist[nr][nc]){
                        dist[nr][nc]=newdiff;
                        pq.push({newdiff,{nr, nc}});
                    }
                }
            }
        }
        return 0;
    }
};