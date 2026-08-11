class Solution {
public:
    vector<int> findAnagrams(string s, string p) {

        vector<int> ans;

        int k = p.length();

        if (k > s.length())
            return ans;

        unordered_map<char, int> freq;

        // Frequency of characters in p
        for (char c : p) {
            freq[c]++;
        }

        int left = 0;
        int count = 0;

        for (int right = 0; right < s.length(); right++) {

            // Add s[right] to window
            freq[s[right]]--;

            // If this character was required
            if (freq[s[right]] >= 0) {
                count++;
            }

            // Window size becomes greater than p.length()
            if (right - left + 1 > k) {

                // Remove s[left]
                freq[s[left]]++;

                // We lost a required character
                if (freq[s[left]] > 0) {
                    count--;
                }

                left++;
            }

            // Window size == p.length()
            if (right - left + 1 == k) {

                // All characters of p are matched
                if (count == k) {
                    ans.push_back(left);
                }
            }
        }

        return ans;
    }
};