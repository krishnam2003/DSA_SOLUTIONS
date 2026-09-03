class Solution {
public:

    int solve(int i, vector<int>& coins, int amount, vector<vector<int>> &dp){
        if(amount == 0){
            return 0;
        }

        if(i < 0){
            return INT_MAX;
        }
        if(dp[i][amount] != -1){
            return dp[i][amount];
        }
        int take = INT_MAX;
        if(amount >= coins[i]){
            int result = solve(i, coins, amount-coins[i], dp);
            if(result != INT_MAX){
                take = 1 + result;
            }
        }

        int skip = solve(i-1, coins, amount, dp);

        return dp[i][amount] = min(take, skip);
    }

    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount+1, -1));
        int ans = solve(n-1, coins, amount, dp);
        if(ans == INT_MAX){
            return -1;
        }

        return ans;
    }
};