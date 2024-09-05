class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        int m=rolls.size(),sumM=0;
        for(auto x:rolls) sumM+=x;
        int rhs=mean*(n+m);
        rhs-=sumM;
        int x=rhs/n,y=rhs%n;
        if(x<=0 || x>6) return {};
        if(x==6 && y>0) return {};
        vector<int>ans(n);
        for(int i=0;i<n;i++){
            ans[i]=x;
        }
        for(int i=0;i<y;i++){
            ans[i]++;
        }
        return ans;
    }
};