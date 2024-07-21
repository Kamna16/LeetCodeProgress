#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool backspaceCompare(string s, string t) {
        vector<char> st1;
        vector<char> st2;
        for(int i=0;i<s.size();i++)
        {
            char c = s[i];
            if (c != '#') {
                st1.push_back(c);
            } else if (!st1.empty()) {
                st1.pop_back();
            }
        }
        for(int i=0;i<t.size();i++)
        {
            char c = t[i];
            if (c != '#') {
                st2.push_back(c);
            } else if (!st2.empty()) {
                st2.pop_back();
            }
        }
        return st1 == st2? true: false;
    }
};