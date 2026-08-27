class Solution {
public:
    string lexGreaterPermutation(string s, string target) {
        int n = s.size();

        int freq[26] = {};

        // Count characters of s
        for (char c : s) {
            freq[c - 'a']++;
        }

        // Try changing target from right to left
        for (int i = n - 1; i >= 0; i--) {

            // We need characters of target[0 ... i-1]
            // to remain the same.
            int temp[26];

            for (int j = 0; j < 26; j++) {
                temp[j] = freq[j];
            }

            // Remove the prefix target[0 ... i-1]
            bool possible = true;

            for (int j = 0; j < i; j++) {
                int x = target[j] - 'a';

                if (temp[x] == 0) {
                    possible = false;
                    break;
                }

                temp[x]--;
            }

            if (!possible)
                continue;

            // At position i, find the smallest
            // character greater than target[i].
            int x = target[i] - 'a';

            for (int c = x + 1; c < 26; c++) {

                if (temp[c] > 0) {

                    string ans = target.substr(0, i);

                    // Make the string greater here
                    ans += char('a' + c);
                    temp[c]--;

                    // Fill remaining characters in sorted order
                    for (int k = 0; k < 26; k++) {
                        while (temp[k] > 0) {
                            ans += char('a' + k);
                            temp[k]--;
                        }
                    }

                    return ans;
                }
            }
        }

        return "";
    }
};