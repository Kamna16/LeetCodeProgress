//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends



class Solution
{
public:
    void findMaximumUtil(string &str, int k, string &maxStr, int index)
    {
        if (k == 0 || index >= str.length()) {
            return;
        }

        char maxChar = *max_element(str.begin() + index, str.end());

        if (maxChar == str[index]) {
            findMaximumUtil(str, k, maxStr, index + 1);
            return;
        }

        for (int i = str.length() - 1; i > index; --i) {
            if (str[i] == maxChar) {
                swap(str[index], str[i]);
                
                if (str > maxStr) {
                    maxStr = str;
                }
                
                findMaximumUtil(str, k - 1, maxStr, index + 1);
                
                swap(str[index], str[i]);
            }
        }
    }

    string findMaximumNum(string str, int k)
    {
        string maxStr = str;
        findMaximumUtil(str, k, maxStr, 0);
        return maxStr;
    }
};

//{ Driver Code Starts.

int main()
{
    int t, k;
    string str;

    cin >> t;
    while (t--)
    {
        cin >> k >> str;
        Solution ob;
        cout<< ob.findMaximumNum(str, k) << endl;
    }
    return 0;
}

// } Driver Code Ends