class Solution {
public:
    int fun(int idx, int buy, vector<int> &prices, vector<vector<int>> &dp) {
        int n = prices.size();
        if (idx >= n) return 0;

        if (dp[idx][buy] != -1) return dp[idx][buy];

        if (buy == 1) {
            // Buy or skip
            return dp[idx][buy] = max(
                -prices[idx] + fun(idx + 1, 0, prices, dp),  // buy
                 fun(idx + 1, 1, prices, dp));               // skip
        } else {
            // Sell or skip
            return dp[idx][buy] = max(
                prices[idx] + fun(idx + 2, 1, prices, dp),  // sell with cooldown
                fun(idx + 1, 0, prices, dp));               // skip
        }
    }

    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n + 2, vector<int>(2, -1));  // n+2 to safely handle idx+2
        return fun(0, 1, prices, dp);
    }
};
