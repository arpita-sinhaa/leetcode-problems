class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        //top priority should be k stop not less dist
        //no need of pq, queue will automatically put less stop one on top
        //as while iterating, stops will inc only,it wont dec, so automatically sorted

        //adj list for identifying neigbours
        vector<vector<pair<int,int>>>adj(n);

        //flights vec is of form(check) from node, to node, wt, so:
        for(auto it: flights){
            int u= it[0];
            int v=it[1];
            int wt= it[2];
            //this line is adding a directed edge from node u to node v with a cost/wt
            adj[u].push_back({v,wt});
        }

        // of format {stops,{node, dist}}
        //queue<pair<int, pair<int,int>>>q;
         priority_queue<pair<int,pair<int,int>>, vector<pair<int, pair<int,int>>>, greater<pair<int, pair<int,int>>>>pq;
        pq.push({0,{src, 0}});

        vector<int>dist(n, INT_MAX);
        dist[src]=0;

        while(!pq.empty()){
            auto it=pq.top();
            pq.pop();

            int stops= it.first;
            int node= it.second.first;
            int cost= it.second.second;

            if(stops>k) continue; //stop

            for(auto i: adj[node]){
                int adjnode= i.first;
                int edgwt= i.second;

                if(cost + edgwt < dist[adjnode] && stops<= k){
                    dist[adjnode]= cost+ edgwt;
                    pq.push({stops+1 , {adjnode , cost+ edgwt}});
                }
            }
        }
        if(dist[dst]== INT_MAX) return -1;
        else return dist[dst];
    }
};