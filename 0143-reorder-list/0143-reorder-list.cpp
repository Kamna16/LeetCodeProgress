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
    ListNode* reverse(ListNode* head) 
    {
        if(head->next == NULL) return head;
        ListNode *newHead =  reverse(head->next);
        head->next->next = head;
        head->next = NULL;

        return newHead;
    }
    void reorderList(ListNode* head) {
        ListNode* slow=head;
        ListNode* fast=head;
        while(fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* rev = reverse(slow);
        ListNode* curr = head;
        while(rev->next != NULL)
        {
            ListNode* tempcurr = curr->next;
            curr->next = rev;

            ListNode* temprev = rev->next;
            rev->next = tempcurr;

            curr = tempcurr;
            rev = temprev;
        }
    }
};