class Solution {
private:
    void permu(vector<int> & nums,vector<vector<int>> &curr,int index ){
        if(index==nums.size()){
            curr.push_back(nums);
            return;
        }
        for(int i=index;i<nums.size();i++){
            swap(nums[i],nums[index]);
            permu(nums,curr,index+1);
            swap(nums[i],nums[index]);
        }
        return;

    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> curr;
        vector<int> ans;
        permu(nums,curr,0);
        return curr;
        
    }
};