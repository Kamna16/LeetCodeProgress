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
        ListNode* prev = new ListNode(-102);
        ListNode* newHead = prev;
        prev->next = curr;
        while(curr && curr->next)
        {
            if(curr->next->val != curr->val)
            {
                prev = curr;
                curr = curr->next;
            }else{
                while(curr->next && curr->next->val == curr->val)
                {
                    curr = curr->next;
                }
                curr = curr->next;
                prev->next = curr;
            }
        }
        return newHead->next;
    }
};