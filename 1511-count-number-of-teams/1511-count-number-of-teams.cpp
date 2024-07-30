class Solution {
public:
    int numTeams(vector<int>& rating) {
        int n = rating.size();
        int count  =0;
        for(int j=1;j<n-1;j++)
        {
            int countSmallerLeft=0, countLargerLeft=0;
            int countSmallerRight=0, countLargerRight=0;
            for(int i=0;i<j;i++)
            {
                if(rating[i]<rating[j]) countSmallerLeft++;
                if(rating[i]>rating[j]) countLargerLeft++;
            }
            for(int i=j;i<n;i++)
            {
                if(rating[i]<rating[j]) countSmallerRight++;
                if(rating[i]>rating[j]) countLargerRight++;
            }
            count+= countSmallerLeft*countLargerRight;
            count+= countLargerLeft*countSmallerRight;
        }
        return count;
    }
};