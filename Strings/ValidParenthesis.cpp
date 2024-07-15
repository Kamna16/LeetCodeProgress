#include<bits/stdc++.h>
using namespace std;

// using stack
class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
		for(int i=0;i<s.length();i++)
		{
			if(st.empty() || s[i] == '(' || s[i] == '{' || s[i] == '[')
			{
				st.push(s[i]);
			}
			else {
                if(s[i] == ')')
				{
                    if(st.top() == '(') st.pop();
                    else return false;
                }
                if(s[i] == '}')
				{
                    if(st.top() == '{') st.pop();
                    else return false;
                }
                if(s[i] == ']')
				{
                    if(st.top() == '[') st.pop();
                    else return false;
                }
			}
		}
		return st.empty();
    }
};