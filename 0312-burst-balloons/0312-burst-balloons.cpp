class Solution {
public:
    int burst(vector<int>& arr, int left, int right, vector<vector<int>>& dp) {
        if (left + 1 == right) return 0;
        if (dp[left][right] != -1) return dp[left][right];
        
        int maxCoins = 0;
        for (int i = left + 1; i < right; ++i) {
            int coins = arr[left] * arr[i] * arr[right];
            coins += burst(arr, left, i, dp);
            coins += burst(arr, i, right, dp);
            maxCoins = max(maxCoins, coins);
        }
        
        dp[left][right] = maxCoins;
        return maxCoins;
    }

    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        vector<int> arr(n + 2, 1);
        
        for (int i = 0; i < n; ++i)
            arr[i + 1] = nums[i];

        // Initialize DP table with -1
        vector<vector<int>> dp(n + 2, vector<int>(n + 2, -1));
        
        return burst(arr, 0, n + 1, dp);
    }
};
