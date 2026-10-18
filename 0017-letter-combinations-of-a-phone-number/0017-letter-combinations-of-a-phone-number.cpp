class Solution {
public:
    unordered_map<char, string> phone = {
            {'2', "abc"}, {'3', "def"}, {'4', "ghi"}, {'5', "jkl"},
            {'6', "mno"}, {'7', "pqrs"}, {'8', "tuv"}, {'9', "wxyz"}
        };

    void solve(int idx, vector<string> &ans, string &path, string digits){
        if(idx == digits.size()){
            ans.push_back(path);
            return;
        }

        char digit = digits[idx];
        string letters = phone[digit];

        for(int i=0; i<letters.size(); i++){
            path.push_back(letters[i]);

            solve(idx+1, ans, path, digits);

            path.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) {
        

        vector<string> ans;
        string path;

        solve(0, ans, path, digits);
        return ans;
    }
};