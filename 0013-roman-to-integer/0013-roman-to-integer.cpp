class Solution {
public:
    int romanToInt(string s) {
        vector<pair<int, string>> roman = {
            {1000, "M"},
            {900, "CM"},
            {500, "D"},
            {400, "CD"},
            {100, "C"},
            {90, "XC"},
            {50, "L"},
            {40, "XL"},
            {10, "X"},
            {9, "IX"},
            {5, "V"},
            {4, "IV"},
            {1, "I"}
        };

        int ans = 0;
        int i = 0;

        for (auto &p : roman) {
            while (i < s.size() && s.substr(i, p.second.size()) == p.second) {
                ans += p.first;
                i += p.second.size();
            }
        }

        return ans;
    }
};