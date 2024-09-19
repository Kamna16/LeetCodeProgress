class Solution {
public:
    vector<int> solve(string s)
    {
        vector<int> res;

        for(int i=0;i<s.size();i++)
        {
            if(s[i] == '+' || s[i] == '-' || s[i] == '*')
            {
                vector<int> left = solve(s.substr(0,i));
            vector<int> right = solve(s.substr(i+1));

            for(int  num1 : left)
            {
                for(int num2 : right)
                {
                    if(s[i] == '+')
                    {
                        res.push_back(num1+num2);
                    }
                    if(s[i] == '-')
                    {
                        res.push_back(num1-num2);
                    }
                    if(s[i] == '*')
                    {
                        res.push_back(num1*num2);
                    }
                    
                }
            }
            }
        }
        if(res.empty()) return {stoi(s)};
        return res;
    }
    vector<int> diffWaysToCompute(string s) {
        return solve(s);
    }
};