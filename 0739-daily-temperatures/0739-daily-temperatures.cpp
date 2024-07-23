class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> answer(n);
        stack<int> st;
        for(int i=n-1;i>=0;i--)
        {
            while(!st.empty() && temperatures[i] >= temperatures[st.top()] ) st.pop();
            if(st.empty())
            {
                answer[i]=0;
            }else{
                answer[i] = st.top() - i;
            }
            st.push(i);
        }
        return answer;
    }
};