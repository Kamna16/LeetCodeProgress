class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        int n = skill.size();
        if(n == 2) return skill[0]*skill[1];
        sort(skill.begin(),skill.end());
        int i=1;
        int j=n-2;
        long long common = skill[0]+skill[n-1];
        long long ans = skill[0]*skill[n-1];
        while(i<j)
        {
            if(skill[i]+skill[j] == common)
            {
                ans += skill[i]*skill[j];
                i++;
                j--;
            }else return -1;
        }
        return ans;
    }
};