class Solution {
public:
 int fun(int idx,int buy,vector<int> & prices,vector<vector<int>>& dp,int fee){
        if(idx==prices.size()) return 0;
        if(dp[idx][buy]!=-1) return dp[idx][buy];
        if(buy){
            return 
            dp[idx][buy]=max(-prices[idx]+fun(idx+1,0,prices,dp,fee), //sell
            0+fun(idx+1,1,prices,dp,fee)); //hold to sell;
        }
        return// if we had done with sell
         dp[idx][buy]=max(prices[idx]+fun(idx+1,1,prices,dp,fee)-fee, //buy
         0+fun(idx+1,0,prices,dp,fee));
    }
    int maxProfit(vector<int>& prices, int fee) {
        vector<vector<int>> dp(prices.size(),vector<int>(2,-1));
        return fun(0,1,prices,dp,fee);
        
    }
};