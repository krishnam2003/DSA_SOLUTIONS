class Solution {
public:
    string minWindow(string s, string t) {
        if(t.size() > s.size()) return "";
        vector<int> freq(128, 0);
        int left = 0;
        int minLen = INT_MAX;
        int cnt = t.size();
        for(auto c : t){
            freq[c]++;
        }
        int start = 0;

        for(int right=0; right<s.size(); right++){
            if(freq[s[right]] > 0){
                cnt--;
            }

            freq[s[right]]--;

            while(cnt == 0){
                if(minLen > right-left+1){
                    minLen = right-left+1;
                    start = left;
                }
                freq[s[left]]++;
                if(freq[s[left]] > 0) cnt++;
                left++;
            }
        }

        if(minLen == INT_MAX) return "";

        return s.substr(start, minLen);
    }
};