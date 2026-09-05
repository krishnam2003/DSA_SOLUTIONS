class Solution {
public:
    int numberOfPermutations(int n, vector<vector<int>>& requirements) {

        const int MOD = 1e9 + 7;
        const int MAX = 400;

        vector<int> req(n, -1);

        // req[end] = required inversion count
        for (auto &r : requirements) {
            req[r[0]] = r[1];
        }

        // dp[j] = ways for current prefix
        vector<long long> dp(MAX + 1, 0);
        dp[0] = 1;

        for (int len = 1; len <= n; len++) {

            vector<long long> ndp(MAX + 1, 0);

            // Add the next element.
            // It can create 0 ... len-1 new inversions.
            for (int inv = 0; inv <= MAX; inv++) {

                if (dp[inv] == 0)
                    continue;

                for (int add = 0; add < len; add++) {

                    if (inv + add > MAX)
                        break;

                    ndp[inv + add] =
                        (ndp[inv + add] + dp[inv]) % MOD;
                }
            }

            dp = ndp;

            // Current prefix ends at index len-1
            if (req[len - 1] != -1) {

                int need = req[len - 1];

                for (int inv = 0; inv <= MAX; inv++) {
                    if (inv != need)
                        dp[inv] = 0;
                }
            }
        }

        return dp[req[n - 1]];
    }
};