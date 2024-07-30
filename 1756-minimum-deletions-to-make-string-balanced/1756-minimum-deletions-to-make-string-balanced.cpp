class Solution {
public:
    int minimumDeletions(string s) {
        int n = s.size();
        int count=0;
        stack<char> st;
        for(int i=0;i<n;i++)
        {
            if(s[i] == 'a')
            {
                if(!st.empty() && st.top() == 'b')
                {
                    count++;
                    st.pop();
                }else st.push(s[i]);
            }else{
                st.push(s[i]);
            }
        }
        return count;
    }
};