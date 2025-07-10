class Solution {
public:
    int fun(int idx,int buy,vector<int> & prices,vector<vector<int>>& dp){
        if(idx==prices.size()) return 0;
        if(dp[idx][buy]!=-1) return dp[idx][buy];
        if(buy){
            return 
            dp[idx][buy]=max(-prices[idx]+fun(idx+1,0,prices,dp), //sell
            0+fun(idx+1,1,prices,dp)); //hold to sell;
        }
        return// if we had done with sell
         dp[idx][buy]=max(prices[idx]+fun(idx+1,1,prices,dp), //buy
         0+fun(idx+1,0,prices,dp));
    }
    int maxProfit(vector<int>& prices) {
        vector<vector<int>> dp(prices.size(),vector<int>(2,-1));
        return fun(0,1,prices,dp);
        
    }
};