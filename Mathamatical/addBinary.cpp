#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string addBinary(string a, string b) {
        string ans = "";
        int i=0;
        char carry=0;
        while(i<a.size() || i<b.size() || carry !=0)
        {
            int x=0;
            if(i<a.size() && a[a.size()-i-1]=='1') x=1;

            int y=0;
            if(i<b.size() && b[b.size()-i-1]=='1') y=1;

            ans = to_string((x+y+carry)%2)+ans;
            carry=(x+y+carry)/2;
            i++;
        }
        return ans;
    }
};