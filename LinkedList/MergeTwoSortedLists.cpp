#include<bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// using 2 pointer
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* temp1 = list1;
        ListNode* temp2 = list2;
        ListNode* current = new ListNode();  // Dummy node for the result list
        ListNode* head = current;  // Store the head of the result list

        while (temp1 != NULL && temp2 != NULL) {
            if (temp1->val <= temp2->val) {
                current->next = new ListNode(temp1->val);
                temp1 = temp1->next;
            } else {
                current->next = new ListNode(temp2->val);
                temp2 = temp2->next;
            }
            current = current->next;
        }

        // If one of the lists is not fully traversed, add the remaining elements
        while (temp1 != NULL) {
            current->next = new ListNode(temp1->val);
            temp1 = temp1->next;
            current = current->next;
        }

        while (temp2 != NULL) {
            current->next = new ListNode(temp2->val);
            temp2 = temp2->next;
            current = current->next;
        }

        return head->next;  // Skip the dummy node
    }
};

// using recursion
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(!list1) return list2;
        if(!list2) return list1;
        ListNode* result;
        if(list1->val <= list2->val)
        {
            result = list1;
            result->next = mergeTwoLists(list1->next,list2);
        }else{
            result = list2;
            result->next = mergeTwoLists(list1,list2->next);
        }
        return result;
    }
};