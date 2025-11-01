class Solution {
public:
    int search(vector<int>& nums, int target) {
       int idx= lower_bound(nums.begin(),nums.end(),target)-nums.begin();
       if(idx<=nums.size()-1 && nums[idx]==target){
        return idx;
       }
       return -1;
        
    }
};