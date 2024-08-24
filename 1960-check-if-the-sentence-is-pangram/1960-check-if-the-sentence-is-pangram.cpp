class Solution {
public:
    bool checkIfPangram(string sentence) {
        int arr[26];
        for(int i=0;i<sentence.size();i++)
        {
            arr[sentence[i]-'a']++;
        }
        for(int i=0;i<26;i++)
        {
            if(arr[i] <= 0) return false;
        }
        return true;
    }
};