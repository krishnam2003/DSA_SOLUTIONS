class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> anagram;
        for(const string &s : strs){
            string key = s;
            sort(key.begin(), key.end());
            anagram[key].push_back(s);
        }

        vector<vector<string>> result;

        for(const auto ans : anagram){
            result.push_back(ans.second);
        }

        return result;
    }
};