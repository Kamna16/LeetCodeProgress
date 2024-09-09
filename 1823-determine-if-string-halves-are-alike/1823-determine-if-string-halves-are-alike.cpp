class Solution {
public:
    bool halvesAreAlike(string s) {
        unordered_set<char> st = {'A','E','I','O','U','a','e','i','o','u'};
        string str1 = s.substr(0,s.length()/2);
        string str2 = s.substr((s.length()/2),s.length()/2);
        int n1 = 0;
        int n2 = 0;
        for(int i=0;i<str1.length();i++)
        {
            if(st.find(str1[i]) != st.end())
            {
                n1++;
            }
        }
        for(int i=0;i<str2.length();i++)
        {
            if(st.find(str2[i]) != st.end())
            {
                n2++;
            }
        }
        if(n1 == n2) return true;
        return false;
    }
};