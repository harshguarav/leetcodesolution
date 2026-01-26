class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
         map<int,int> freq;
        for(int arr:nums){
            freq[arr]++;
        }
        for(auto &p:freq){
            if(p.second>=2) return true;
        }
        return false;
    }
};