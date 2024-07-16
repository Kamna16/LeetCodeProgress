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
    bool isPalindrome(int i, int j, vector<int> &arr)
    {
        if(i>j) return true;
        if(arr[i]==arr[j]) return isPalindrome(i+1,j-1,arr);
        return false;
    }
    bool isPalindrome(ListNode* head) {
        vector<int> arr;
        ListNode* curr = head;
        while(curr != NULL)
        {
            arr.push_back(curr->val);
            curr = curr->next;
        }
        return isPalindrome(0,arr.size()-1,arr);
    }
};