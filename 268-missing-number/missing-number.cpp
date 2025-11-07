class Solution {
public:
    int missingNumber(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int size=nums.size();
        for(int i=0;i<nums.size();i++){
            if(nums[i]!=i){
                return i;

            }
        }
        return size;
        
    }
};