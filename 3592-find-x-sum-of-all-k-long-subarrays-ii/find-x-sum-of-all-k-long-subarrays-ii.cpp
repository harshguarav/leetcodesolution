#include <bits/stdc++.h>
using namespace std;

struct Cmp {
    bool operator()(const pair<int,int>& a, const pair<int,int>& b) const {
        if (a.first != b.first) return a.first > b.first;  // higher freq first
        return a.second > b.second;                        // tie → higher value first
    }
};

class Solution {
public:
    vector<long long> findXSum(vector<int>& nums, int k, int x) {
        int n = nums.size();
        unordered_map<int,int> freq;
        multiset<pair<int,int>, Cmp> topX, others;
        long long sumTop = 0;
        vector<long long> ans;

        auto addPair = [&](pair<int,int> p){
            if ((int)topX.size() < x) {
                topX.insert(p);
                sumTop += 1LL * p.first * p.second;
            } else {
                auto last = prev(topX.end());
                if (Cmp()(p, *last)) {
                    others.insert(*last);
                    sumTop -= 1LL * last->first * last->second;
                    topX.erase(last);
                    topX.insert(p);
                    sumTop += 1LL * p.first * p.second;
                } else {
                    others.insert(p);
                }
            }
        };

        auto erasePair = [&](pair<int,int> p){
            auto it = topX.find(p);
            if (it != topX.end()) {
                sumTop -= 1LL * p.first * p.second;
                topX.erase(it);
                if (!others.empty()) {
                    auto nxt = *others.begin();
                    topX.insert(nxt);
                    sumTop += 1LL * nxt.first * nxt.second;
                    others.erase(others.begin());
                }
            } else {
                auto it2 = others.find(p);
                if (it2 != others.end()) others.erase(it2);
            }
        };

        auto updateFreq = [&](int val, int delta){
            int oldF = freq[val];
            if (oldF > 0) erasePair({oldF, val});
            freq[val] += delta;
            int newF = freq[val];
            if (newF > 0) addPair({newF, val});
        };

        // Initialize first window
        for (int i = 0; i < k; i++) updateFreq(nums[i], +1);
        ans.push_back(sumTop);

        // Slide window
        for (int i = k; i < n; i++) {
            updateFreq(nums[i - k], -1);
            updateFreq(nums[i], +1);
            ans.push_back(sumTop);
        }

        return ans;
    }
};
