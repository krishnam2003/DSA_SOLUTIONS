#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> LastIndex(256, -1); // store last position
        int left = 0;
        int maxLen = 0;

        for(int right = 0; right < s.length(); right++) {
            
            if(LastIndex[s[right]] >= left) {
                left = LastIndex[s[right]] + 1;
            }

            LastIndex[s[right]] = right;
            maxLen = max(maxLen, right - left + 1);
        }

        return maxLen;
    }
};