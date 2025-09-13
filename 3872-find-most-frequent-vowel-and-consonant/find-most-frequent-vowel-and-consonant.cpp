class Solution {
public:
    int maxFreqSum(string s) {
        unordered_map<char,int> vo;
        unordered_map<char,int> co;
        for(char ch:s){
            if(ch=='a' || ch=='e' ||ch=='i' ||ch=='o'||ch=='u'){
        
                vo[ch]++;
            }
            else{
                int m=ch-'a';
                co[ch]++;
            }
        }
        int maxV=0;
        for(auto& check: vo){
            maxV=max(maxV,check.second);

        }
        int maxC=0;
         for(auto& check: co){
            maxC=max(maxC,check.second);

        }
        return maxV+maxC;
        
    }
};