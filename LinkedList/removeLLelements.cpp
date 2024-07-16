#include<bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* dummy = new ListNode(-1);
        dummy->next = head;
        ListNode* curr = dummy;
        while(curr->next != NULL)
        {
            if(curr->next->val == val)
            {
                curr->next = curr->next->next;
            }else{
                curr = curr->next;
            }
        }
        return dummy->next;
    }
};