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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* curr = head;
        ListNode* prev = new ListNode(INT_MIN);
        prev->next = curr;
        while(curr)
        {
            if(curr->val != prev->val)
            {
                prev = curr;
                curr = curr->next;
            }else{
                prev->next = curr->next;
                curr = curr->next;
            }
        }
        return head;
    }
};