class Solution {
public:
    int minDeletions(string s) {
        unordered_map<char, int> freq;
        for (char c : s) {
            freq[c]++;
        }
        
        vector<int> counts;
        for (auto& p : freq) {
            counts.push_back(p.second);
        }
        
        sort(counts.begin(), counts.end(), greater<int>());
        
        int deletions = 0;
        for (int i = 1; i < counts.size(); i++) {
            while (i < counts.size() && counts[i] >= counts[i - 1] && counts[i] > 0) {
                counts[i]--;
                deletions++;
            }
        }
        
        return deletions;
    }
};
