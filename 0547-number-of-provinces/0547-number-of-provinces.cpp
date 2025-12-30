class Solution {
   
public:

     void dfs(int node, vector<vector<int>>& adjList, vector<int>& visited){
            visited[node] = 1;
            for(auto nbr : adjList[node]){
                if(!visited[nbr]){
                    dfs(nbr, adjList, visited);
                }
            }
        }


    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<int> visited(n, 0);
        int count = 0;

        vector<vector<int>> adjList(n);
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(isConnected[i][j] == 1 && i != j){
                    adjList[i].push_back(j);
                    adjList[j].push_back(i);
                }
            }
        }

        for(int i=0; i<n; i++){
            if(visited[i] == 0){
                count++;
                dfs(i, adjList, visited);
            }
        }

        return count;
    }
};

// without making adjacency list

/*



        void dfs(int node, vector<vector<int>>& adjList, vector<int>& visited){
            visited[node] = 1;
            for(int j=0; j<isConnected.size(); j++){
                if(isConnected[node][j] == 1 && !visited[j]){
                    dfs(j, adjList, visited);
                }
            }
        }

*/