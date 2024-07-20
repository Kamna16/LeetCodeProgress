#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string simplifyPath(string path) {
        string result = "";
        stack<string> st;
        stringstream ss(path);
        string token;
        while(getline(ss,token,'/'))
        {
            if(token == "" || token == ".") continue;
            if(token != "..")
            {
                st.push(token);
            }else if(!st.empty()) st.pop();
        }
        if(st.empty()) return "/";

        while(!st.empty())
        {
            result = '/'+st.top()+result;
            st.pop();
        }
        return result;
    }
};