class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> st;
        int maxArea = 0;
        int n = heights.size();

        for (int i = 0; i <= n; i++) {
            int currHeight = (i == n) ? 0 : heights[i];
            while (!st.empty() && currHeight < heights[st.top()]) {
                int h = heights[st.top()];
                st.pop();
                int width = st.empty() ? i : i - st.top() - 1;
                maxArea = max(maxArea, h * width);
            }
            st.push(i);
        }
        return maxArea;
    }

    int maximalRectangle(vector<vector<char>>& matrix) {
        int row = matrix.size();
        if (row == 0) return 0;
        int col = matrix[0].size();
        vector<vector<int>> dp(row, vector<int>(col, 0));

        for (int i = 0; i < col; i++) {
            for (int j = 0; j < row; j++) {
                if (matrix[j][i] == '0') {
                    dp[j][i] = 0;
                } else {
                    if (j == 0) {
                        dp[j][i] = 1;
                    } else {
                        dp[j][i] = 1 + dp[j - 1][i];
                    }
                }
            }
        }

        int maxArea = 0;
        for (int i = 0; i < row; i++) {
            maxArea = max(maxArea, largestRectangleArea(dp[i]));
        }

        return maxArea;
    }
};
