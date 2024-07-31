class Solution {
public:
      int evalRPN(vector<string>& tokens) {
        int n = tokens.size();
        stack<int>st;
        for(int i=0;i<n;i++){
            if(tokens[i] == "+" or tokens[i] == "-" or tokens[i] == "*" or tokens[i] == "/"){
                    int num1 = st.top(); st.pop();
                    int num2 = st.top(); st.pop();
                    int newNum = 0;
                    if(tokens[i] == "+") newNum = num2+num1;
                    else if(tokens[i] == "-") newNum = num2-num1;
                    else if(tokens[i] == "*") newNum = num2*num1;
                    else newNum = num2/num1;
                    st.push(newNum);
            }
            else st.push(stoi(tokens[i]));
        }
        return st.top();
      }
};