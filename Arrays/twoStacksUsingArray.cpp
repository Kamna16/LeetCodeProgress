#include <bits/stdc++.h>
using namespace std;

class twoStacks {
public:
    std::vector<int> arr;
    int top1, top2;
    
    twoStacks(int size = 100) {
        arr.resize(size);
        top1 = -1;
        top2 = size;
    }

    void push1(int x) {
        top1++;
        arr[top1] = x;
    }

    void push2(int x) {
        top2--;
        arr[top2] = x;
    }

    int pop1() {
        if (top1 >= 0) {
            int x = arr[top1];
            top1--;
            return x;
        } else {
            return -1;  
        }
    }

    int pop2() {
        if (top2 < arr.size()) {
            int x = arr[top2];
            top2++;
            return x;
        } else {
            return -1;  
        }
    }
};


int main() {

    int T;
    cin >> T;
    while (T--) {
        twoStacks *sq = new twoStacks();

        int Q;
        cin >> Q;
        while (Q--) {
            int stack_no;
            cin >> stack_no;
            int QueryType = 0;
            cin >> QueryType;

            if (QueryType == 1) {
                int a;
                cin >> a;
                if (stack_no == 1)
                    sq->push1(a);
                else if (stack_no == 2)
                    sq->push2(a);
            } else if (QueryType == 2) {
                if (stack_no == 1)
                    cout << sq->pop1() << " ";
                else if (stack_no == 2)
                    cout << sq->pop2() << " ";
            }
        }
        cout << endl;
    }
}
