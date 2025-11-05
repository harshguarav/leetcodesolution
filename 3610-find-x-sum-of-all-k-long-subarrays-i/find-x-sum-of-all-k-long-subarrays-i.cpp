#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findXSum(vector<int>& nums, int k, int x) {
        int n = nums.size();
        vector<int> ans;

        for (int i = 0; i + k <= n; i++) {
            // Step 1: count frequencies in current subarray
            unordered_map<int, int> freq;
            for (int j = i; j < i + k; j++) {
                freq[nums[j]]++;
            }

            // Step 2: store (freq, value) pairs
            vector<pair<int, int>> items;
            for (auto &p : freq) {
                items.push_back({p.second, p.first});
            }

            // Step 3: sort by frequency desc, value desc
            sort(items.begin(), items.end(), [](auto &a, auto &b) {
                if (a.first != b.first) return a.first > b.first;
                return a.second > b.second;
            });

            // Step 4: collect top x values
            unordered_set<int> keep;
            for (int j = 0; j < min(x, (int)items.size()); j++) {
                keep.insert(items[j].second);
            }

            // Step 5: compute sum of kept elements in subarray
            long long sum = 0;
            for (int j = i; j < i + k; j++) {
                if (keep.count(nums[j])) sum += nums[j];
            }

            ans.push_back(sum);
        }

        return ans;
    }
};

