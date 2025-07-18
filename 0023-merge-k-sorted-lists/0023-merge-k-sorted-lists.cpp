/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<int,vector<int>,greater<int>> heap;
        for(int i=0;i<lists.size();i++){
            while(lists[i]){
                heap.push(lists[i]->val);
                lists[i]=lists[i]->next;

            }
        }
        ListNode* dummy=new ListNode(0);
        ListNode* tail=dummy;
        while(heap.size()>0){
            tail->next=new ListNode(heap.top());
            heap.pop();
            tail=tail->next;

        }
        return dummy->next;
    }
};