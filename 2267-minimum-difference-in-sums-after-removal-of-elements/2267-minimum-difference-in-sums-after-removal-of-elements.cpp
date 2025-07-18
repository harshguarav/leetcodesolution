class Solution {
public:
    long long minimumDifference(vector<int>& nums) {
        int len = nums.size();
        int n = len / 3;

        // Store min prefix sums of n largest from left
        vector<long long> left(len, 0);
        priority_queue<int> maxHeap;
        long long sumLeft = 0;

        for (int i = 0; i < len; ++i) {
            sumLeft += nums[i];
            maxHeap.push(nums[i]);

            if (maxHeap.size() > n) {
                sumLeft -= maxHeap.top();
                maxHeap.pop();
            }

            if (maxHeap.size() == n) {
                left[i] = sumLeft;
            }
        }

        // Store max suffix sums of n smallest from right
        vector<long long> right(len, 0);
        priority_queue<int, vector<int>, greater<int>> minHeap;
        long long sumRight = 0;

        for (int i = len - 1; i >= 0; --i) {
            sumRight += nums[i];
            minHeap.push(nums[i]);

            if (minHeap.size() > n) {
                sumRight -= minHeap.top();
                minHeap.pop();
            }

            if (minHeap.size() == n) {
                right[i] = sumRight;
            }
        }

        long long minDiff = LLONG_MAX;

        // Now try all valid splits between left and right
        for (int i = n - 1; i < 2 * n; ++i) {
            minDiff = min(minDiff, left[i] - right[i + 1]);
        }

        return minDiff;
    }
};
