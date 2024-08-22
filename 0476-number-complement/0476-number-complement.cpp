class Solution {
public:
    int findComplement(int num) {
       int bitLength = (int)(log2(num))+1;
       for(int i=0;i<bitLength;i++)
       {
         num = num ^ (1<<i);
       }
       return num;
    }
};