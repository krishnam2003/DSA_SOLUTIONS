class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        
        vector<vector<int>> reverseAdjList(n);
        vector<int> indegree(n, 0);
        for(int i=0; i<n; i++){
            for(auto& it : graph[i]){
                reverseAdjList[it].push_back(i); // reverse the adj list to make outdegree to indegree of terminal node
                indegree[i]++;
            }
        }

        queue<int> q;
        for(int i=0; i<n; i++){
            if(indegree[i] == 0){
                q.push(i);
            }
        }
        vector<int> topo;
        while(!q.empty()){
            int f = q.front();
            q.pop();
            topo.push_back(f);
            for(int nbr : reverseAdjList[f]){
                indegree[nbr]--;
                if(indegree[nbr] == 0){
                    q.push(nbr);
                }
            }
        }

        sort(topo.begin(), topo.end());

        return topo;
    }
};