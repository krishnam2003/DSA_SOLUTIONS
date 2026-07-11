class Solution {
public:

    void dfs(int node, int n, vector<vector<int>> &adj, vector<int>& visited, int &vertices, int &totalEdges){
        visited[node] = 1;
        vertices  = vertices + 1;
        totalEdges = totalEdges + adj[node].size();
        for(int & nbr : adj[node]){
            if(!visited[nbr]){
                dfs(nbr, n, adj, visited, vertices, totalEdges);
            }
        }

        
    }

    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        for(auto & it : edges){
            int u = it[0];
            int v = it[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        int NoOfConComponents = 0;  //count
        vector<int> visited(n,0);
        
        //edges = vertices*(vertices-1) / 2;
        //for complete graph
        //if we manage to count the no of nodes and edges somehow, we can find the complete graph 
        for(int i=0; i<n; i++){
            if(!visited[i] ){
                int vertices = 0;
                int totalEdges = 0;
                dfs(i,n,adj,visited,vertices, totalEdges);
                if(totalEdges/2 == (vertices*(vertices-1))/2 ){
                    NoOfConComponents++;
                }
            }
        }

        return NoOfConComponents;
    }
};