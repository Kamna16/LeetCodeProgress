#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int val;
    Node* next;
    Node* random;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};

class Solution {
public:
    Node* copyRandomList(Node* head) {
        unordered_map<Node* , Node*> mp;
        Node* newHead = new Node(-1);
        Node* curr1 = head;
        Node* prev = newHead;
        // traverse for data and next ptr
        while(curr1!= NULL)
        {
            Node* newNode = new Node(curr1->val);
            prev->next = newNode;
            prev = prev->next;
            mp[curr1] = newNode;
            curr1 = curr1->next;
        }
        Node* curr = head;
        Node* Head = newHead->next;
        while(curr != NULL)
        {
            Head->random = mp[curr->random];
            curr = curr->next;
            Head = Head->next;
        }
        return newHead->next;
    }
};