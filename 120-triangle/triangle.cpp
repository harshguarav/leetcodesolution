class Solution {
public:
    int minSum(vector<vector<int>>& triangle, int x, int y, vector<vector<int>>& dp) {
        int m = triangle.size();
        
        if (x >= m || y >= triangle[x].size()) return INT_MAX;

        if (x == m - 1) return triangle[x][y]; // Base case: bottom row

        if (dp[x][y] != INT_MAX) return dp[x][y];

        int down = minSum(triangle, x + 1, y, dp);
        int diag = minSum(triangle, x + 1, y + 1, dp);

        return dp[x][y] = triangle[x][y] + min(down, diag);
    }

    int minimumTotal(vector<vector<int>>& triangle) {
        int m = triangle.size();
        vector<vector<int>> dp(m);

        for (int i = 0; i < m; i++) {
            dp[i].resize(triangle[i].size(), INT_MAX);
        }

        return minSum(triangle, 0, 0, dp);
    }
};
