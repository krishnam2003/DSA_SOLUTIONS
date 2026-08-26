class Solution {
public:
    void solve(int start, int n, int k, vector<vector<int>>& ans, vector<int>& current){
        
        if(current.size() == k){
            ans.push_back(current);
            return;
        }

        for(int i=start; i<=n; i++){
            current.push_back(i);

            solve(i+1, n, k, ans, current);
            
            current.pop_back();

        }

        
    }

    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        vector<int> current;

        

        solve(1, n, k, ans, current);
        return ans;
    }
};