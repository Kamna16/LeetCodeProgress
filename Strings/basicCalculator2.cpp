#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int calculate(string s) {
        stack<int> myStack;
        char sign = '+';
        long long res = 0, currNum = 0;
        for (int i = 0; i < s.size(); i++) {
            if (isdigit(s[i]))
                currNum = 10*currNum + s[i]-'0';
            if (!isdigit(s[i]) && !isspace(s[i]) || i == s.size()-1) {
                if (sign == '-')
                    myStack.push(-currNum);
                else if (sign == '+')
                    myStack.push(currNum);
                else {
                    int num;
                    if (sign == '*' )
                        num = myStack.top()*currNum;
                    else
                        num = myStack.top()/currNum;
                    myStack.pop();
                    myStack.push(num);
                } 
                sign = s[i];
                currNum = 0;
            }
        }
        while (!myStack.empty()) {
            res += myStack.top();
            myStack.pop();
        }
        return res;
    }
};