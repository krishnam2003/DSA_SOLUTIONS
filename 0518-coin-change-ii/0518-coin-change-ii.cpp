class Solution {
public:
    int solve(int i, vector<int>& coins, int amount, vector<vector<int>>& dp){
        if(amount == 0){
            return 1;
        }

        if(i < 0){
            return 0;
        }

        if(dp[i][amount] != -1){
            return dp[i][amount];
        }

        int take = 0;

        if(amount >= coins[i]){
            take = solve(i, coins, amount-coins[i], dp);
        }

        int skip = solve(i-1, coins, amount, dp);

        return dp[i][amount] = (take + skip);
    }

    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount+1, -1));
        int ans = solve(n-1, coins, amount, dp);

        return ans;
    }
};