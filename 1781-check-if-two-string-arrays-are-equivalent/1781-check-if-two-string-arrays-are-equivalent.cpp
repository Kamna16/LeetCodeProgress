class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        string str1 = ""; 
        string str2 = "";
        for(int i=0;i<word1.size();i++)
        {
            for(auto ch : word1[i])
            {
                str1 += ch;
            }
        } 
        for(int i=0;i<word2.size();i++)
        {
            for(auto ch : word2[i])
            {
                str2 += ch;
            }
        }
        if(str1 == str2) return true;
        return false;

    }
};