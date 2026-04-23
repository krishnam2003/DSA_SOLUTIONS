class Solution {
public:
    vector<long long> distance(vector<int>& nums) {
        int n = nums.size();
        vector<long long> ans(n, 0);
        
        unordered_map<int, vector<int>> mp;
        
        // Step 1: Group indices
        for (int i = 0; i < n; i++) {
            mp[nums[i]].push_back(i);
        }
        
        // Step 2: Process each group
        for (auto &p : mp) {
            vector<int> &idx = p.second;
            int k = idx.size();
            
            vector<long long> prefix(k, 0);
            prefix[0] = idx[0];
            
            for (int i = 1; i < k; i++) {
                prefix[i] = prefix[i-1] + idx[i];
            }
            
            for (int i = 0; i < k; i++) {
                long long left = 0, right = 0;
                
                if (i > 0) {
                    left = (long long)idx[i] * i - prefix[i-1];
                }
                
                if (i < k-1) {
                    right = (prefix[k-1] - prefix[i]) - (long long)idx[i] * (k-i-1);
                }
                
                ans[idx[i]] = left + right;
            }
        }
        
        return ans;
    }
};