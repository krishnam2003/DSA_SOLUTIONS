class Solution {
public:
    int solve(int i, int buy, int cap, int n, vector<vector<vector<int>>> &dp, vector<int>& prices){
        if(i == n || cap == 0) return 0;
        if(dp[i][buy][cap] != -1) return dp[i][buy][cap];
        int profit = 0;
        if(buy){
             profit = max(-prices[i] + solve(i+1 , 0, cap, n, dp, prices),
                            solve(i+1, 1, cap, n, dp, prices));
        }
        else{
            profit = max(prices[i]+solve(i+1, 1, cap-1, n, dp, prices),
                            solve(i+1, 0, cap, n, dp, prices));
        }

        return dp[i][buy][cap] = profit;
    }

    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(2, vector<int>(k+1, -1)));

        return solve(0, 1, k, n, dp, prices);
    }
};