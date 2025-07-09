class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int row = matrix.size();
        if (row == 0) return 0;
        int col = matrix[0].size();
        vector<vector<int>> dp(row, vector<int>(col, 0));

        // Step 1: Build the dp matrix of histogram heights
        for (int i = 0; i < col; i++) {
            for (int j = 0; j < row; j++) {
                if (matrix[j][i] == '0') {
                    dp[j][i] = 0;
                } else {
                    dp[j][i] = (j == 0) ? 1 : dp[j - 1][i] + 1;
                }
            }
        }

        int maxArea = 0;

        // Step 2: For each row in dp, treat it as histogram
        for (int i = 0; i < row; i++) {
            vector<int> histogram = dp[i];
            vector<int> LTR(col), RTL(col);

            // Left to right expansion
            for (int j = 0; j < col; j++) {
                int count = j + 1;
                int sum = histogram[j];
                while (count < col && histogram[count] >= histogram[j]) {
                    sum += histogram[j];
                    count++;
                }
                LTR[j] = sum;
            }

            // Right to left expansion
            for (int j = col - 1; j >= 0; j--) {
                int count = j - 1;
                int sum = histogram[j];
                while (count >= 0 && histogram[count] >= histogram[j]) {
                    sum += histogram[j];
                    count--;
                }
                RTL[j] = sum;
            }

            // Combine both sides and find max area in this histogram
            for (int j = 0; j < col; j++) {
                int area = LTR[j] + RTL[j] - histogram[j];
                maxArea = max(maxArea, area);
            }
        }

        return maxArea;
    }
};
