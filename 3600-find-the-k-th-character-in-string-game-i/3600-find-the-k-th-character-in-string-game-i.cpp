class Solution {
public:
    char kthCharacter(int k) {
        string s = "a";
        while(s.size() < k)
        {
            string temp = "";
            for(char c : s)
            {
                temp += ++c;
            }
            s = s+ temp;
        }
        return s[k-1];
    }
};