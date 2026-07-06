class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        unordered_map<int, int> mp;
        for(auto &it : edges){
            int u = it[0];
            int v = it[1];

            mp[u]++;
            mp[v]++;
        }

        for(auto &x : mp){
            if(x.second == edges.size()){
                return x.first;
            }
        }

        return -1;
    }
};