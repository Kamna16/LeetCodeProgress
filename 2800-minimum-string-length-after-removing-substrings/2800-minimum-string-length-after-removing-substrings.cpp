class Solution {
public:
    int minLength(string s) {
        string s1 = "AB";
        string s2 = "CD";
        stack<char> st;
        for(int i=0;i<s.size();i++)
        {
            if(!st.empty())
            {
                string str = string(1, st.top()) + s[i];
                if(str == s1 || str == s2)
                {
                    st.pop();
                }else st.push(s[i]);
            }else {
                st.push(s[i]); 
            }
        }
        return st.size();
    }
};