#include<bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
// 1) store in array and then find decimal
// 2) reverse the ll and then find decimal

class Solution {
public:
    int getDecimalValue(ListNode* head) {
        int result = 0;
        ListNode* temp = head;
        while(temp!= NULL)
        {
            result *= 2;
            result += temp -> val;
            temp = temp -> next;

        }return result;
    }
};