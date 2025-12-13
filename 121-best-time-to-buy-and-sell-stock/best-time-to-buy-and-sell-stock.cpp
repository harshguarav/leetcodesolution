class Solution {
public:
   int maxProfit(vector<int>& prices) {
    int curr = 0, best = 0;

    for (int i = 1; i < prices.size(); i++) {
        curr += prices[i] - prices[i - 1];
        curr = max(curr, 0);
        best = max(best, curr);
    }
    return best;
}

};