class Solution {
public:

    int solve(int i, int buy, int n, vector<vector<int>>& dp, vector<int>& prices){
        if(i == n) return 0;
        if(dp[i][buy] != -1) return dp[i][buy];
        int profit = 0;
        if(buy){
             profit = max(-prices[i] + solve(i+1 , 0, n, dp, prices),
                            solve(i+1, 1, n, dp, prices));
        }
        else{
            profit = max(prices[i]+solve(i+1, 1, n, dp, prices),
                            solve(i+1, 0, n, dp, prices));
        }

        return dp[i][buy] = profit;
    }

    int maxProfit(vector<int>& prices) {
        int n = prices.size();

        vector<vector<int>> dp(n, vector<int>(2, -1));

        // dp[0][0] = 0;
        // dp[0][1] = 0;

        // for(int i=n-1; i>=0; i--){
        //     for(int j=0; j<2; j++){
        //         if()
        //     }
        // }

        return solve(0, 1, n, dp, prices);
    }
};