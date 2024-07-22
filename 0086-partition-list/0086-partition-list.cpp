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
    ListNode* partition(ListNode* head, int x) {
        ListNode* curr = head;
        ListNode* leftHead = new ListNode(0);
        ListNode* rightHead= new ListNode(0);
        ListNode* l = leftHead;
        ListNode* r = rightHead;
        while(curr)
        {
            if(curr->val < x)
            {
                l->next = new ListNode(curr->val);
                l = l->next;
            }else{
                rightHead->next = new ListNode(curr->val);
                rightHead = rightHead->next;
            }
            curr = curr->next;
        }
        l->next = r->next;
        return leftHead->next;
    }
};