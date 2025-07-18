class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> maxheap;
        for(int num:stones){
            maxheap.push(num);
        }
        while(maxheap.size()>1){
            int first=maxheap.top();
            maxheap.pop();
            int second=maxheap.top();
            maxheap.pop();
            int result=abs(first-second);
            maxheap.push(result);
        }
        return maxheap.top();
        
    }
};