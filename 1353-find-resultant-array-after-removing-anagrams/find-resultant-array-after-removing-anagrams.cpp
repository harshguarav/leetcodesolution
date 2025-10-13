class Solution {
public:
    vector<string> removeAnagrams(vector<string>& words) {
        vector<string> result;
        string prevSorted = ""; // To store sorted version of previous word
        
        for (string word : words) {
            string sortedWord = word;
            sort(sortedWord.begin(), sortedWord.end());
            
            // Only add if not an anagram of the previous
            if (sortedWord != prevSorted) {
                result.push_back(word);
                prevSorted = sortedWord;
            }
        }
        return result;
    }
};
