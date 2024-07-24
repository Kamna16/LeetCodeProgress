#include<bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    //Function to evaluate a postfix expression.
    int evaluatePostfix(string s)
    {
        stack<int> st;
        for(int i=0;i<s.length();i++)
        {
            if(isdigit(s[i]))
            {
                int str = s[i]-'0';
                st.push(str);
            }else{
                int num1 = st.top();
                st.pop();
                int num2 = st.top();
                st.pop();
                if(s[i] == '*')
                {
                    int ans = num2 * num1;
                    st.push(ans);
                }else if(s[i] == '+')
                {
                    int ans = num2 + num1;
                    st.push(ans);
                }else if(s[i] == '/')
                {
                    int ans = num2 / num1;
                    st.push(ans);
                }else{
                    int ans = num2 - num1;
                    st.push(ans);
                }
            }
        }
        return st.top();
    }
};