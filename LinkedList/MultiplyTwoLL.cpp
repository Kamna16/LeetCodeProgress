#include <bits/stdc++.h>
using namespace std;


struct Node {
    int data;
    struct Node *next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

/* Function to create a new Node with given data */
struct Node *newNode(int data) {
    struct Node *new_Node = new Node(data);

    return new_Node;
}

Node *reverse(Node **r) {
    Node *prev = NULL;
    Node *cur = *r;
    Node *nxt;
    while (cur != NULL) {
        nxt = cur->next;
        cur->next = prev;
        prev = cur;
        cur = nxt;
    }
    *r = prev;
}

/* Function to insert a Node at the beginning of the Doubly Linked List */
void push(struct Node **head_ref, int new_data) {
    /* allocate Node */
    struct Node *new_Node = newNode(new_data);

    /* link the old list off the new Node */
    new_Node->next = (*head_ref);

    /* move the head to point to the new Node */
    (*head_ref) = new_Node;
}

void freeList(struct Node *Node) {
    struct Node *temp;
    while (Node != NULL) {

        temp = Node;
        Node = Node->next;
        free(temp);
    }
}

class solution {
  public:
    long long multiplyTwoLists(Node *first, Node *second) {
        long long MOD = 1000000007; 
        long long str1 = 0;
        long long str2 = 0;
        
        Node* curr1 = first;
        Node* curr2 = second;
        
        while (curr1 != NULL) {
            str1 = (str1 * 10 + curr1->data) % MOD;
            curr1 = curr1->next;
        }
        
        while (curr2 != NULL) {
            str2 = (str2 * 10 + curr2->data) % MOD;
            curr2 = curr2->next;
        }
        
        return (str1 * str2) % MOD;
    }
};

void printList(struct Node *Node) {
    while (Node != NULL) {
        printf("%d ", Node->data);
        Node = Node->next;
    }
    printf("\n");
}

int main(void) {

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {

        struct Node *first = NULL;
        struct Node *second = NULL;
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;

        while (ss >> number) {
            arr.push_back(number);
        }
        for (int i = 0; i < arr.size(); i++) {
            push(&first, arr[i]);
        }
        vector<int> brr;
        string input2;
        getline(cin, input2);
        stringstream ss2(input2);
        int number1;
        while (ss2 >> number1) {
            brr.push_back(number1);
        }
        for (int i = 0; i < brr.size(); i++) {
            push(&second, brr[i]);
        }
        reverse(&first);
        reverse(&second);
        solution ob;
        long long res = ob.multiplyTwoLists(first, second);
        cout << res << endl;
        freeList(first);
        freeList(second);
    }
    return 0;
}
