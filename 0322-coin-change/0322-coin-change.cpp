class Solution {
public:
    unordered_map<int, int> memo;

    int coinChange(vector<int>& coins, int amount) {
        int ans = helper(coins, amount);
        return (ans == INT_MAX) ? -1 : ans;
    }

    int helper(vector<int>& coins, int amount) {
        if (amount == 0) return 0;
        if (amount < 0) return INT_MAX;

        // Check if already computed
        if (memo.count(amount)) return memo[amount];

        int minCoins = INT_MAX;

        for (int coin : coins) {
            int res = helper(coins, amount - coin);
            if (res != INT_MAX) {
                minCoins = min(minCoins, res + 1);
            }
        }

        // Memoize the result
        memo[amount] = minCoins;
        return minCoins;
    }
};
