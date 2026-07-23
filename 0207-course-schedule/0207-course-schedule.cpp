class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);

        for(int i=0; i<prerequisites.size(); i++){
            int u=prerequisites[i][1];
            int v=prerequisites[i][0];
            adj[u].push_back(v);
        }

        vector<int> indegree(numCourses,0);
        for(int i=0; i<numCourses; i++){
            for(auto it: adj[i]){
                indegree[it]++;
            }
        }

        queue<int> q;
        for(int i=0; i<indegree.size(); i++){
            if(indegree[i]==0) q.push(i);
        }

        vector<int> toposort;

        while(!q.empty()){
            int node=q.front();
            q.pop();
            toposort.push_back(node);

            for(auto it: adj[node]){
                indegree[it]--;
                if(indegree[it]==0) q.push(it);
            }
        }
        return toposort.size()==numCourses;
    }
};