class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        int n = arr.size();
        
        // Step 1: Build prefix XOR
        vector<int> pref(n);
        pref[0] = arr[0];
        
        for (int i = 1; i < n; i++) {
            pref[i] = pref[i - 1] ^ arr[i];
        }
        
        // Step 2: Answer queries
        vector<int> result;
        
        for (auto &q : queries) {
            int L = q[0], R = q[1];
            
            if (L == 0) {
                result.push_back(pref[R]);
            } else {
                result.push_back(pref[R] ^ pref[L - 1]);
            }
        }
        
        return result;
    }
};