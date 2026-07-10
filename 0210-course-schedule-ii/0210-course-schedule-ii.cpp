class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        int V = numCourses; 
        vector<vector<int>> adj(V);
        vector<int> indegree(V, 0);
        for(auto& x : prerequisites){
            int u = x[1];
            int v = x[0];

            adj[u].push_back(v);
        }
        for(int i=0; i<numCourses; i++){
            for(int nbr : adj[i]){
                indegree[nbr]++;
            }
        }

        queue<int> q;
        for(int i=0; i<numCourses; i++){
            if(indegree[i] == 0){
                q.push(i);
            }
        }

        vector<int> topo;

        while(!q.empty()){
            int f = q.front();
            q.pop();
            topo.push_back(f);
            for(int nbr : adj[f]){
                indegree[nbr]--;
                if(indegree[nbr] == 0){
                    q.push(nbr);
                }
            }
        }
        if(topo.size() == V) return topo;
        return {};
    }
};