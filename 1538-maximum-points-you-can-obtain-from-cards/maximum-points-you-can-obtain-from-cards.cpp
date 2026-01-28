class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int sum=0;
        for(int i=0;i<k;i++){
            sum=sum+cardPoints[i];
        }
        int maxi=sum;
        for(int i=0;i<k;i++){
           sum = sum - cardPoints[k - 1 - i]
      + cardPoints[cardPoints.size() - 1 - i];

            maxi=max(sum,maxi);
        }
        return maxi;
    }
};