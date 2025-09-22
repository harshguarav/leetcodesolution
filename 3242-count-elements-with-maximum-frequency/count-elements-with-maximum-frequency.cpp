class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        unordered_map<int,int> freq;
        for(int num:nums){
            freq[num]++;
        }
        int maxi=0;
        for(auto& num:freq){
            maxi=max(maxi,num.second);
        }
        int  sum=0;
        for(auto& num:freq){
            if(num.second==maxi){
                sum=sum+maxi;
            }

        }
        return sum;
        
    }
};