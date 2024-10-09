class Solution {
public:
    int minAddToMakeValid(string s) {
        int n = s.size();
        stack<int> st;
        int count = 0;
        for(int i=0;i<n;i++)
        {
            if(s[i] == '(') st.push(s[i]);
            else{
                if(!st.empty())
                {
                    st.pop();
                }else count++;
            }
        }
        if(st.size() > 0) return count+st.size();
        return count;
    }
};