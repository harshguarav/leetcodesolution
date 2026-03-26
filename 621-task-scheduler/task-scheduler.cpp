class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> freq(26, 0);

        for(char t : tasks){
            freq[t - 'A']++;
        }

        int maxFreq = *max_element(freq.begin(), freq.end());

        int countMaxFreq = 0;
        for(int f : freq){
            if(f == maxFreq) countMaxFreq++;
        }

        int partCount = maxFreq - 1;
        int partLength = n + 1;

        int formula = partCount * partLength + countMaxFreq;

        return max((int)tasks.size(), formula);
    }
};