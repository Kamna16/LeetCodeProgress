#include<bits/stdc++.h>
using namespace std;

// using Sorting Method
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n = strs.size();
        sort(strs.begin(), strs.end());
        string str1 = strs[0];
        string str2 = strs[n-1];
        string answer = "";
        int i=0;
        while(i<str1.size() )
        {
            if(str1[i] == str2[i])
            {
                answer+= str1[i];
                i++;
            }
            else break;
        }
        return answer;
    }
};