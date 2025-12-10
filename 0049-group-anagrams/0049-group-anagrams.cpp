class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> anagrams;
        for(string &s: strs ){
            string key = s;
            sort(key.begin(), key.end());
            anagrams[key].push_back(s);

        }
        vector<vector<string>> result;
        for(auto ans: anagrams){
            result.push_back(ans.second);
        }

        return result;
    }
};