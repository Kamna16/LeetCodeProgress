class Solution {
public:
    void recur(vector<int>& candidates,int ind, int target, vector<int> &list,vector<vector<int>> &ans)
    {
        if(target == 0)
        {
            ans.push_back(list);
            return;
        }

        for(int i=ind;i<candidates.size();i++)
        {
            if(i>ind && candidates[i]==candidates[i-1]) continue;
            if(candidates[i]>target) break;

            //pick
            list.push_back(candidates[i]);
            recur(candidates,i+1,target-candidates[i],list,ans);
            //not pick
            list.pop_back();
        
        }
        

    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<int> list;
        vector<vector<int>> ans;
        recur(candidates,0,target,list,ans);
        return ans;
    }
};