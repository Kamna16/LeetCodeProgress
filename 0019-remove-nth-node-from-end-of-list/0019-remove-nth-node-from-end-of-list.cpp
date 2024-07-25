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
        ListNode* curr = head;
        ListNode* prev = NULL;
        while(curr != NULL)
        {
            ListNode* temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }
        return prev;
    }
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* newHead = reverse(head);
        int i = 1;
        ListNode* curr = newHead;
        ListNode* dummy = new ListNode(-1);
        dummy->next = curr;
        ListNode* prev = dummy;
        while(curr != NULL)
        {
            if(i == n)
            {
                prev->next = curr->next;
                break;
            }else{
                prev = curr;
                curr = curr->next;
                i++;
            }
        }
        return reverse(dummy->next);
    }
};