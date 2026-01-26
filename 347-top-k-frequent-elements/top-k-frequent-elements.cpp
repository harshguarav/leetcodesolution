class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> map;
        for(int i:nums){
            map[i]++;
        }
        priority_queue<pair<int,int>> pq;
        for(auto &p: map){
            pq.push({p.second,p.first});
        }
        vector<int> result;
        for(int i=0;i<k;i++){

            result.push_back(pq.top().second);
            pq.pop();
        }
        return result;
    }
};