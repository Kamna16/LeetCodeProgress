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
    int Length(ListNode* head)
    {
        int count = 1;
        while(head != NULL)
        {
            count++;
            head = head->next;
        }
        return count;
    }
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int len1 = Length(headA);
        int len2 = Length(headB);

        while(len1>len2)
        {
            len1--;
            headA=headA->next;
        }
        while(len2>len1)
        {
            len2--;
            headB=headB->next;
        }

        while(headA != headB)
        {
            headA=headA->next;
            headB=headB->next;
        }
        return headA;
    }
};