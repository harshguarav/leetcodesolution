class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // int maxlen=0;
        // for(int i=0;i<s.length();i++){
        //     vector<int> hash(256,0);
        //     for(int j=i;j<s.length();j++){
        //         if(hash[s[j]]==1) break;
        //         int len=j-i+1;
        //         maxlen=max(maxlen,len);
        //         hash[s[j]]=1;

        //     }
        // }
        // return maxlen;
        vector<int> hash(256,-1);
        int l=0;
        int r=0;
        int maxlen=0;
        while(r<s.length()){
           if(hash[s[r]]!=-1){
            l=max(l,hash[s[r]]+1);
           }
            hash[s[r]]=r;
            maxlen=max(maxlen,r-l+1);
            r++;
        }
        return maxlen;
    }
};