class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<vector<int>> Radj(n);
        vector<int> indegree(n, 0);
        for(int i=0; i<n; i++){
            for(auto& nbr : graph[i]){
                Radj[nbr].push_back(i);
                indegree[i]++;
            }
        }

        queue<int> q;
        for(int i=0; i<n; i++){
            if(indegree[i] == 0){
                q.push(i);
            }
        }
        vector<int> ans;
        while(!q.empty()){
            int f = q.front();
            q.pop();
            ans.push_back(f);
            for(int nbr : Radj[f]){
                indegree[nbr]--;
                if(indegree[nbr] == 0){
                    q.push(nbr);
                }
            }
        }

        sort(ans.begin(), ans.end());

        return ans;
    }
};