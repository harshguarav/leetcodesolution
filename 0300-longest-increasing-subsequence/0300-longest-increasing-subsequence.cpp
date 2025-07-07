class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;

        std::set<int> ans;
        for (int i = 0; i < n; i++) {
            auto it = ans.lower_bound(nums[i]);
            if (it != ans.end()) {
                ans.erase(it);  // Replace the first ≥ nums[i]
            }
            ans.insert(nums[i]);  // Insert current element
        }
        return ans.size();
    }
};
