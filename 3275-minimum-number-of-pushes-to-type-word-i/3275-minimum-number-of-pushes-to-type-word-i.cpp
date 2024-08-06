class Solution {
public:
    int minimumPushes(string word) {
        int n = word.size();
        unordered_map<int,int> mp;
        int sum =0;
        int assign =2;
        for(char ch : word)
        {
            if(assign > 9) assign =2;

            mp[assign]++;
            sum+= mp[assign];
            assign++;
        }
        return sum;
    }
};