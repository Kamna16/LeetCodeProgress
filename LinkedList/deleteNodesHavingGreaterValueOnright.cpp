//{ Driver Code Starts
#include<bits/stdc++.h>

using namespace std;

struct Node
{
    int data;
    Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};

class Solution
{
    public:
    Node* reverse(Node* head) {
        Node* prev = nullptr;
        Node* curr = head;
        while (curr != nullptr) {
            Node* nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
        }
        return prev;
    }

    Node* compute(Node* head) {
        // Reverse the linked list
        head = reverse(head);

        Node* maxNode = nullptr;
        Node* curr = head;

        // Traverse the reversed list and construct result list
        while (curr != nullptr) {
            if (maxNode == nullptr || curr->data >= maxNode->data) {
                Node* nextNode = curr->next;
                curr->next = maxNode;
                maxNode = curr;
                curr = nextNode;
            } else {
                curr = curr->next;
            }
        }

        return maxNode;
    }
    
};