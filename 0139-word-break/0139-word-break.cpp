class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        vector<bool> result(s.length() + 1, false);
        result[0] = true;

        for (int i = 1; i <= s.length(); i++) {
            for (int j = 0; j < i; j++) {
                string str = s.substr(j, i - j);
                if (result[j] && find(wordDict.begin(), wordDict.end(), str) != wordDict.end()) {
                    result[i] = true;
                    break;  // ✅ stop early if one match found
                }
            }
        }

        return result[s.length()];
    }
};
