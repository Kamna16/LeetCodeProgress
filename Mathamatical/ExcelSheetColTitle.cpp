#include<bits/stdc++.h>
using namespace std;


//log(colNum) base 26
class Solution {
public:
    string convertToTitle(int columnNumber) {
      int colNum=columnNumber;
      string ans="";
      while(colNum>0)
      {
        colNum--; // to handle remainder = 0
        int remainder = colNum%26;
        ans+= remainder+'A';
        colNum = colNum/26;
      } 
      reverse(ans.begin(),ans.end());
      return ans;
    }
};