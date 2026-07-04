class Solution {
public:
    bool wordPattern(string pattern, string s) {
        vector<string> words;
        stringstream ss(s);
        string token;

        int countWords = 0;
        while(getline(ss, token, ' ')){
            words.push_back(token);
            countWords++;
        }

        if(pattern.size() != countWords){
            return false;
        }

        unordered_map<string, char> mp;
        unordered_set<char> used;

        for(int i=0; i<pattern.size(); i++){
            char ch = pattern[i];
            string word = words[i];
            if(mp.find(word) == mp.end() && used.find(ch) == used.end()){
                mp[word] = ch;
                used.insert(ch);
            }
            else if(mp[word] != ch){
                return false;
            }
        }

        return true;
    }
};