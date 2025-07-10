class Solution {
public:
int fun(int idx,int buy,vector<int> & prices,vector<vector<vector<int>>>& dp,int cap){
    if(idx==prices.size() || cap==0) return 0;
    if (dp[idx][buy][cap]!=-1)return dp[idx][buy][cap];
    if(buy){
        return
        dp[idx][buy][cap]=max(-prices[idx]+fun(idx+1,0,prices,dp,cap),
        0+fun(idx+1,1,prices,dp,cap));
    }
    return 
    dp[idx][buy][cap]=max(prices[idx]+fun(idx+1,1,prices,dp,cap-1),
    0+fun(idx+1,0,prices,dp,cap));
}
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
         vector<vector<vector<int>>> dp(n, vector<vector<int>>(2, vector<int>(3, -1)));
         return fun(0,1,prices,dp,2);

    }
};