class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        sort(coins.begin(), coins.end());  // Sort to safely use coins[m]
        vector<int> dp(amount + 1, amount + 1); 
        dp[0] = 0;

        // Fill initial unreachable values with -1
        int idx = 1;
        while (idx < coins[0] && idx <= amount) {
            dp[idx] = -1;
            idx++;
        }

        int m = 0;

        for (int i = idx; i <= amount; ++i) {
            // If current i is exactly equal to coin[m], we need only 1 coin
            if (m < coins.size() && i == coins[m]) {
                dp[i] = 1;
                m++;
            } 
            else {
                dp[i] = -1; // assume not possible

                for (int j = 0; j < coins.size(); j++) {
                    int prev = i - coins[j];
                    if (prev >= 0 && dp[prev] != -1) {
                        if (dp[i] == -1) dp[i] = dp[prev] + 1;
                        else dp[i] = min(dp[i], dp[prev] + 1);
                    }
                }
            }
        }

        return dp[amount];
    }
};
