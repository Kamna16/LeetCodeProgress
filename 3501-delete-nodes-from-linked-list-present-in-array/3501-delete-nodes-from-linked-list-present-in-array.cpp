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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        unordered_set<int> numSet(nums.begin(), nums.end());
        ListNode* curr = head;
        ListNode* prev = new ListNode(-1);
        ListNode* newHead = prev;
        prev->next = curr;
        while(curr)
        {
            int value = prev->next->val;
            if(numSet.find(value) != numSet.end())
            {
                prev->next = curr ->next;
                curr = curr->next;
            }else{
                prev = prev->next;
                curr = curr ->next;
            }
        }
        return newHead->next;
    }
};
