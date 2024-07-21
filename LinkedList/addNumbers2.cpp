#include<bits/stdc++.h>
using namespace std;

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
    ListNode* reverse(ListNode* head) {
        if (head == NULL || head->next == NULL) return head;
        ListNode *newHead = reverse(head->next);
        head->next->next = head;
        head->next = NULL;
        return newHead;
    }

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if (l1 == NULL) return l2;
        if (l2 == NULL) return l1;
        
        ListNode* new1 = reverse(l1);
        ListNode* new2 = reverse(l2);
        
        ListNode* dummy = new ListNode(0);
        ListNode* curr = dummy;
        int carry = 0;
        
        while (new1 != NULL || new2 != NULL || carry != 0) {
            int sum = carry;
            if (new1 != NULL) {
                sum += new1->val;
                new1 = new1->next;
            }
            if (new2 != NULL) {
                sum += new2->val;
                new2 = new2->next;
            }
            carry = sum / 10;
            sum = sum % 10;
            
            curr->next = new ListNode(sum);
            curr = curr->next;
        }
        
        ListNode* result = reverse(dummy->next);
        
        return result;
    }
};
