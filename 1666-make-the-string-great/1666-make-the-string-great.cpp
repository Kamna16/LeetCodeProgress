class Solution {
public:
    string makeGood(string s) {
        string res = "";
        for(int i=0;i<s.length();i++)
        {
            if(!res.empty() && abs(res.back()-s[i]) == 32)
            {
                res.pop_back();
            }else{
                res.push_back(s[i]);
            }
        }
        return res;
    }
};