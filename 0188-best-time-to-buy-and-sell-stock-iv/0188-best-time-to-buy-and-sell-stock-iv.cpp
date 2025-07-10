class Solution {
public:
    int fun(int idx, int buy, int k, vector<int>& prices, vector<vector<vector<int>>>& dp) {
        if (idx == prices.size() || k == 0) return 0;

        if (dp[idx][buy][k] != -1) return dp[idx][buy][k];

        if (buy) {
            // Option 1: Buy the stock
            // Option 2: Skip buying
            return dp[idx][buy][k] = max(
                -prices[idx] + fun(idx + 1, 0, k, prices, dp), // buy
                 fun(idx + 1, 1, k, prices, dp));              // skip
        } else {
            // Option 1: Sell the stock → reduce transaction count
            // Option 2: Skip selling
            return dp[idx][buy][k] = max(
                prices[idx] + fun(idx + 1, 1, k - 1, prices, dp), // sell
                fun(idx + 1, 0, k, prices, dp));                  // skip
        }
    }

    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        // Dimensions: day × buy/sell × transactions left
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(2, vector<int>(k + 1, -1)));
        return fun(0, 1, k, prices, dp);
    }
};
