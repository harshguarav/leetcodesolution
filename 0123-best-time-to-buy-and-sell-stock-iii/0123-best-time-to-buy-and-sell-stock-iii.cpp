class Solution {
public:
    int maxProfit(vector<int>& prices) {
        vector<int> leftToRight(prices.size(),0);
        int minLeft=prices[0];
        int buy=0;
        for(int i=0;i<prices.size();i++){
            
            buy=max(buy,prices[i]-minLeft);
            leftToRight[i]=buy;
            minLeft = min(minLeft, prices[i]);
            
        }
        vector<int> rightToLeft(prices.size(),0);
        int minRight=prices[prices.size()-1];
        int sell=0;
        for(int i=prices.size()-1;i>=0;i--){
            sell=max(sell,minRight-prices[i]);
            rightToLeft[i]=sell;
            minRight = max(minRight, prices[i]);
        }
        int result=0;
        for(int i=0;i<prices.size();i++){
            result=max(result,leftToRight[i]+rightToLeft[i]);

        }
        return result;

        
    }
};