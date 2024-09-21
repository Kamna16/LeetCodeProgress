class Solution {
public:
    vector<int> lexicalOrder(int n) {
        vector<int> ans;
        for(int i=1;i<=n;i++)
        {
            ans.push_back(i);
        }
        auto myComparator = [](int a, int b)
        {
            string s1 = to_string(a);
            string s2 = to_string(b);
            return s1<s2;
        };
        sort(ans.begin(),ans.end(),myComparator);
        return ans;
    }
};