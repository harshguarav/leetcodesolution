class Solution {
public:
    void generate(int n , string curr,vector<string>& ans){
        if(curr.length()==n){
            ans.push_back(curr);
            return;
        }

        for(char c:{'a','b','c'}){
            if(curr.empty() || curr.back()!=c){
                curr.push_back(c);
                generate(n,curr,ans);
                curr.pop_back();
            }
        }
    }
    string getHappyString(int n, int k) {
        vector<string> ans;
        generate(n,"",ans);
        if(k>ans.size()) return "";
        return ans[k-1];
        
    }
};