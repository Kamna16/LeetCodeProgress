class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n = s2.size();
	   int m = s1.size();
	   unordered_map<char,int> mp;
	   for(int i=0;i<m;i++)
	   {
	       mp[s1[i]]++;
	   }
	   int i=0, j=0;
	   while(j<n)
	   {
	       mp[s2[j]]--;
	       
	       if(j-i+1 == m)
	       {
	           bool greater = false;
	           for(auto p : mp)
	           {
	               int count = p.second;
	               if(count >= 1){
	                   greater=true;
	                   break;
	               }
	           }
	           if(!greater){
                return true;
               }
	           
	           mp[s2[i]]++;
	           i++;
	       }
	       j++;
	   }
	   
	   return false;
    }
};