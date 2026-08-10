class Solution {
public:
    int longestSubstring(string s, int k) {
        int n = s.size();
        if(k > n) return 0;
        unordered_map<char, int> mp;
        for(int i=0; i<n; i++){
            mp[s[i]]++;
        }

        
        for(int i = 0; i < n; i++){
            if(mp[s[i]] < k){
                int left = longestSubstring(s.substr(0, i), k);
                int right = longestSubstring(s.substr(i + 1), k);

                return max(left, right);
            }

            
        }

        return n;
    }
};