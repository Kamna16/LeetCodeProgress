class Solution {
public:
    long long findEquVal(pair<int,int> &p1, pair<int,int> &p2, pair<int,int> p3)
    {
        long long x1 = p1.first;
        long long x2 = p2.first;
        long long x3 = p3.first;
        long long y1 = p1.second;
        long long y2 = p2.second;
        long long y3 = p3.second;

        return (y3-y2)*(x2-x1) - (y2-y1)*(x3-x2);
    }
    vector<vector<int>> outerTrees(vector<vector<int>>& trees) {
        int n = trees.size();
        if (n <= 3) return trees;
        sort(trees.begin(),trees.end());
        vector<vector<int>> res;

        deque<pair<int,int>> upper, lower;

        for(auto pt : trees)
        {
            int l = lower.size();
            int u = upper.size();

            while(l>=2 && findEquVal(lower[l-2],lower[l-1],{pt[0], pt[1]}) <0)
            {
                l--;
                lower.pop_back();
            }
            while(u>=2 && findEquVal(upper[u-2],upper[u-1],{pt[0], pt[1]}) >0)
            {
                u--;
                upper.pop_back();
            }
            upper.push_back({pt[0],pt[1]});
            lower.push_back({pt[0],pt[1]});
        }

        set<pair<int,int>> st;
        for(auto pt : upper)
        {
            st.insert(pt);
        }
        for(auto pt : lower)
        {
            st.insert(pt);
        }
        for(auto pt : upper)
        {
            st.insert(pt);
        }
        for(auto pt : st)
        {
            res.push_back({pt.first,pt.second});
        }
        return res;
    }
};