class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        vector<vector<pair<int, double>>> adj(n);
        for(int i=0; i<edges.size(); i++){
            int u = edges[i][0];
            int v = edges[i][1];
            double pr = succProb[i];

            double cost = -log(pr);
            adj[u].push_back({v, cost});
            adj[v].push_back({u, cost});
        }
        priority_queue<pair<double, int>, vector<pair<double, int>>, greater<pair<double, int>>> pq;
        vector<double> dist(n, DBL_MAX);
        dist[start_node] = 0.0;
        pq.push({0.0, start_node});

        while(!pq.empty()){
            auto [pro, node] = pq.top();
            pq.pop();

            if(pro > dist[node]) continue;
            for(auto [v, pr] : adj[node]){
                if(dist[v] > dist[node] + pr){
                    dist[v] = dist[node] + pr;
                    pq.push({dist[v], v});
                }
            }
        }

        if(dist[end_node] == DBL_MAX) return 0.0;

        return exp(-dist[end_node]);

    }
};