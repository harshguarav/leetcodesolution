class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        // sort(nums.begin(),nums.end(),greater<int>());
        // return nums[k-1];


        // doing this using pripority_queue max

        priority_queue<int> maxheap;

        for(int num:nums){
            maxheap.push(num);
        }
        int result;
        for(int i=0;i<k;i++){
            result=maxheap.top();
            maxheap.pop();

        }
        return result;
        
    }
};