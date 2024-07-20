#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string intToRoman(int num) {
       vector<pair<int, string>> mp = {
            {1000, "M"}, {900, "CM"}, {500, "D"}, {400, "CD"},
            {100, "C"}, {90, "XC"}, {50, "L"}, {40, "XL"},
            {10, "X"}, {9, "IX"}, {5, "V"}, {4, "IV"}, {1, "I"}
        };

        string result = "";
        for (auto& value : mp) {
            int count = num / value.first;
            num %= value.first;
            for (int i = 0; i < count; ++i) {
                result += value.second;
            }
        }
        return result;
    }
};