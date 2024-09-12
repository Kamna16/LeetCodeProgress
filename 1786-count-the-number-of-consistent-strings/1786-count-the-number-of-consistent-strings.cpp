class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        int n = words.size();
        unordered_set<char> mp;
        int count =0;
        for(int i=0;i<allowed.size();i++)
        {
           mp.insert(allowed[i]);
        }
        for(int i=0;i<n;i++)
        {
            string curr = words[i];
            bool flag = true;
            for(int j=0;j<curr.size();j++)
            {
                if(mp.find(curr[j]) == mp.end()) flag = false;
            }
            if(flag) count++;
        }
        return count;
    }
};