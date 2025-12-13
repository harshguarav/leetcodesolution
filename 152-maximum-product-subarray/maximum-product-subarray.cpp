class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxp=nums[0];
        int minp=nums[0];
        int ans=nums[0];
        for(int i=1;i<nums.size();i++){
            int x=nums[i];

            int tempmax=max({x,maxp*x,minp*x});
            int tempmin=min({x,maxp*x,minp*x});

            maxp=tempmax;
            minp=tempmin;

            ans=max(ans,maxp);
            

        }
        return ans;
    }
};