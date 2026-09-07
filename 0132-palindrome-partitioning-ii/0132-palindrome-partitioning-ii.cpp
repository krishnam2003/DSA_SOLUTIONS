class Solution {
public:

    int solve(int i, int j,
              string& s,
              vector<vector<int>>& dp,
              vector<vector<bool>>& pal) {

        // Already a palindrome
        if (i >= j || pal[i][j])
            return 0;

        if (dp[i][j] != -1)
            return dp[i][j];

        int ans = INT_MAX;

        for (int k = i; k < j; k++) {

            if (pal[i][k]) {

                int cost = solve(i, k, s, dp, pal)
                         + solve(k + 1, j, s, dp, pal)
                         + 1;

                ans = min(ans, cost);
            }
        }

        return dp[i][j] = ans;
    }

    int minCut(string s) {

        int n = s.size();

        vector<vector<bool>> pal(
            n, vector<bool>(n, false)
        );

        // Precompute palindrome table
        for (int i = n - 1; i >= 0; i--) {

            for (int j = i; j < n; j++) {

                if (s[i] == s[j] &&
                    (j - i <= 1 || pal[i + 1][j - 1])) {

                    pal[i][j] = true;
                }
            }
        }

        vector<vector<int>> dp(
            n, vector<int>(n, -1)
        );

        return solve(0, n - 1, s, dp, pal);
    }
};