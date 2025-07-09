class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        sort(coins.begin(), coins.end());  // ensure coins are sorted
        vector<int> dp(amount + 1, -1);
        dp[0] = 0;

        int idx = 1;
        while (idx < coins[0] && idx <= amount) {
            dp[idx] = -1;
            idx++;
        }

        int m = 0;

        for (int i = idx; i <= amount; ++i) {
            if (m < coins.size() && i == coins[m]) {
                dp[i] = 1;
                m++;
            } else {
                int minVal = INT_MAX;
                int k = 0;

                // manually check coins less than current amount i
                while (k < coins.size() && coins[k] < i) {
                    int prev = i - coins[k];
                    if (dp[prev] != -1) {
                        minVal = min(minVal, dp[prev] + 1);
                    }
                    k++;
                }

                if (minVal != INT_MAX)
                    dp[i] = minVal;
                else
                    dp[i] = -1;
            }
        }

        return dp[amount];
    }
};
