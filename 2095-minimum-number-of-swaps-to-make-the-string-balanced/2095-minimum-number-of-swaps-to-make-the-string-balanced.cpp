class Solution {
public:
    int minSwaps(string s) {
        if(s.size() == 0) return 0;

        stack<char> st;
        for(int i=0;i<s.size();i++)
        {
            if(s[i] == '[') st.push(s[i]);
            else{
                if(!st.empty() && st.top() == '[')
                {
                    st.pop();
                }
            }
        }
        return (st.size()+1)/2;
    }
};