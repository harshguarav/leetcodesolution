class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        vector<bool> result(s.length(),false);
        result[0]=true;
        for(int i=1;i<s.length()+1;i++){
            for(int j=0;j<i;j++){
                string str=s.substr(j,i-j);
                if(find(wordDict.begin(),wordDict.end(),str)!=wordDict.end() && result[j]){
                    result[i]=true;
                    // break;
                }
            }
        }
        return result[s.length()];
        
    }
};