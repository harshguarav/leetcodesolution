#include <algorithm>
using namespace std;

class Solution {
public:
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        if (!head) return nullptr;

        // Step 1: sort nums for efficient searching
        sort(nums.begin(), nums.end());

        // Step 2: handle deletions safely with dummy node
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* curr = dummy;

        // Step 3: traverse once
        while (curr->next != nullptr) {
            // use binary_search instead of scanning nums linearly
            if (binary_search(nums.begin(), nums.end(), curr->next->val)) {
                curr->next = curr->next->next; // remove node
            } else {
                curr = curr->next;
            }
        }

        return dummy->next;
    }
};
