class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        // vector<vector<int>> adj(numCourses);
        // vector<int> indegree(numCourses, 0);
        // for(auto& x : prerequisites){
        //     int u = x[0];
        //     int v = x[1];

        //     adj[v].push_back(u);
        // }
        // for(int i=0; i<numCourses; i++){
        //     for(int nbr : adj[i]){
        //         indegree[nbr]++;
        //     }
        // }

        // queue<int> q;
        // for(int i=0; i<numCourses; i++){
        //     if(indegree[i] == 0){
        //         q.push(i);
        //     }
        // }

        // vector<int> ans;

        // while(!q.empty()){
        //     int f = q.front();
        //     q.pop();
        //     ans.push_back(f);
        //     for(int nbr : adj[f]){
        //         indegree[nbr]--;
        //         if(indegree[nbr] == 0){
        //             q.push(nbr);
        //         }
        //     }
        // }
        // return ans.size() == numCourses;
        int V = numCourses;
        vector<vector<int>> adj(V);
        for(auto it : prerequisites){
            int u = it[1];
            int v = it[0];
            adj[u].push_back(v);
        }

        vector<int> indegree(V,0);
        for(int i=0; i<V; i++){
            for(int &nbr : adj[i]){
                indegree[nbr]++;
            }
        }

        

        queue<int> q;
        vector<int> topo;
        for(int i=0; i<V; i++){
            if(indegree[i] == 0){
                q.push(i);
            }
        }
        while(!q.empty()){
            int f = q.front();
            q.pop();
            topo.push_back(f);
            for(auto &nbr : adj[f]){

                indegree[nbr]--;
                if(indegree[nbr] == 0){
                    q.push(nbr);
                }
                
            }
        }

        if(topo.size() == V) return true;
        return false;
    }
};