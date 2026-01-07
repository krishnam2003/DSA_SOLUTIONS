class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
         vector<vector<int>> adj(numCourses);
        vector<int> indegree(numCourses, 0);
        for(auto& x : prerequisites){
            int u = x[0];
            int v = x[1];

            adj[v].push_back(u);
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

        vector<int> ans;

        while(!q.empty()){
            int f = q.front();
            q.pop();
            ans.push_back(f);
            for(int nbr : adj[f]){
                indegree[nbr]--;
                if(indegree[nbr] == 0){
                    q.push(nbr);
                }
            }
        }
        if(ans.size() < numCourses){
            return {};
        }
        else{
            return ans;
        }
    }
};