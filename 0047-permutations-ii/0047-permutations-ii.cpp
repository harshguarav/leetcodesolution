class Solution {
public:
//so in permutation we have to use used array to check the particular element is used or not
    void fun(vector<int>& nums,vector<vector<int>>& result,vector<bool>& used,vector<int> & subarr){
        int n=nums.size();
        
        if(subarr.size()==nums.size()){
            result.push_back(subarr);
            return;
        }
        for(int i=0;i<n;i++){
            if(used[i]) continue;
            if(i>0 && nums[i]==nums[i-1] && !used[i-1]){
               continue;
            
            }
                used[i]=true;
                subarr.push_back(nums[i]);
                fun(nums,result,used,subarr);
                subarr.pop_back();
                used[i]=false;
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> result;
        vector<int> subarr;
        vector<bool> used(nums.size(),false);
        fun(nums,result,used,subarr);
        return result;
        
    }
};