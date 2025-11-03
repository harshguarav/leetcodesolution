class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int totalCost = 0;
        
        for (int i = 1; i < colors.size(); i++) {
            if (colors[i] == colors[i - 1]) {
                // Remove the one with smaller neededTime
                totalCost += min(neededTime[i], neededTime[i - 1]);
                // Keep the one with the larger time for the next comparison
                neededTime[i] = max(neededTime[i], neededTime[i - 1]);
            }
        }
        
        return totalCost;
    }
};
