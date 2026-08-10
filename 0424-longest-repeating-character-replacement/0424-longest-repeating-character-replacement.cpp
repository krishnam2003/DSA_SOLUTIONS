class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size();
        unordered_map<char, int> mp;
        int maxFreq = 0;
        int maxLen = 0;

        int left = 0;

        for(int right = 0; right < n; right++){
            mp[s[right] - 'A']++;

            maxFreq = max(maxFreq, mp[s[right] - 'A']);
            
            while((right-left+1) - maxFreq > k){
                mp[s[left] - 'A']--;

                left++;
            }

            if((right-left+1) - maxFreq <= k){
                maxLen = max(maxLen, right-left+1);
            }
        }

        return maxLen;
    }
};