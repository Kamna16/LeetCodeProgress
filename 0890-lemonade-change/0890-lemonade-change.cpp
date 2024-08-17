class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int n = bills.size();
        unordered_map<int,int> mp;
       for(int i : bills)
       {
            if(i==5)
            {
                mp[i]++;                                     
            }
            else if(i == 10)
            {
                if(mp[5] >0) 
                {
                    mp[5]--;
                    mp[i]++;
                }else return false;
            }else{
                if(mp[10] > 0 && mp[5] > 0)
                {
                    mp[5]--; 
                    mp[10]--;
                }
                else if(mp[5]>=3) 
                {
                    mp[5]--;
                    mp[5]--;
                    mp[5]--; 
                }else return false;
            }
       }
       return true;
    }
};