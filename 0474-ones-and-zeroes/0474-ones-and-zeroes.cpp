class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        
        for (const string& str : strs) {
           
            int zeros = 0, ones = 0;
            for (char c : str) {
                if (c == '0') zeros++;
                else ones++;
            }
            
            // Process in reverse to avoid reusing same string
            for (int j = m; j >= zeros; j--) {
                for (int k = n; k >= ones; k--) {
                    dp[j][k] = max(dp[j][k], dp[j - zeros][k - ones] + 1);
                }
            }
        }
        
        return dp[m][n];
    }
};