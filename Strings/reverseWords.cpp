#include<bits/stdc++.h>
using namespace std;

// 1) using stringStream
// 1) using 2 pointer

class Solution {
public:
    string reverseWords(string s) {
        reverse(s.begin(),s.end());
        int i=0;
        int n = s.length();
        int l=0,r=0;
        while(i<n)
        {
            while(i<n && s[i] != ' ')
            {
               s[r]=s[i];
                i++;
                r++;
            }
            if(l<r)
            {
                reverse(s.begin()+l, s.begin()+r);
                s[r]= ' ';
            r++;
            l=r;
            }
            i++;
            
        }
        s= s.substr(0, r-1);
        return s;
    }
};