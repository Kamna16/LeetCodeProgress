class Solution {
public:
    string reverseWords(string s) {
        reverse(s.begin(),s.end());
        int l=0, r=0;
        string ans= "";
        while(l < s.size() && s[l] ==' '){
            l++;
            r++;
        }
        while(r<s.length())
        {
            while(r < s.size() && s[r] != ' ') r++;
            string str = s.substr(l,r-l);
            reverse(str.begin(),str.end());
            ans += str;
            ans += " ";
            while(r < s.size() && s[r] == ' ')
            {
                r++;
            }
            l = r;
        }
        if (!ans.empty()) ans.pop_back();
        return ans;
    }
};