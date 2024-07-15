#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle) {
        int i,j;
        int len1=haystack.size(), len2=needle.size();
        for (i = 0; i <= len1-len2; i++) {
            for (j = 0; j <len2; j++) {
                if (haystack[i + j] != needle[j]) {
                    break;
                }
            }
            if (j == len2) {
                return i;
            }
        }
        return -1;
    }
};