class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size();

        unordered_map<char, int> mp;

        int maxFreq = 0;
        int maxLen = 0;
        int left = 0;

        for (int right = 0; right < n; right++) {

            // Add current character
            mp[s[right]]++;

            // Maximum frequency in current window
            maxFreq = max(maxFreq, mp[s[right]]);

            // If replacements needed > k, shrink window
            while ((right - left + 1) - maxFreq > k) {

                mp[s[left]]--;

                if (mp[s[left]] == 0) {
                    mp.erase(s[left]);
                }

                left++;
            }

            // Update answer
            maxLen = max(maxLen, right - left + 1);
        }

        return maxLen;
    }
};