class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int n = s.size();
	   int m = p.size();
	   unordered_map<char,int> mp;
	   for(int i=0;i<m;i++)
	   {
	       mp[p[i]]++;
	   }
	   vector<int> ans;
	   int i=0, j=0;
	   while(j<n)
	   {
	       mp[s[j]]--;
	       
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
                ans.push_back(i);
               }
	           
	           mp[s[i]]++;
	           i++;
	       }
	       j++;
	   }
	   
	   return ans;
    }
};