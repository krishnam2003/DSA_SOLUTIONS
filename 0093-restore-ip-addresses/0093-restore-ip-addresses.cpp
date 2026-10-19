class Solution {
public:
    bool isValid(string s){
        if(s[0] == '0'){
            return false;
        }

        int n = stoi(s);

        if(n > 255){
            return false;
        }

        return true;
    }
    
    void solve(int idx, int part, string curr, vector<string>& ans, string s){
        int n = s.size();
        if(part == 4 && idx == s.size()){
            curr.pop_back();
            ans.push_back(curr);
        }

        if(idx+1 <= n){
            solve(idx+1, part+1, curr+s.substr(idx, 1)+".", ans, s);
        }

        if(idx+2 <= n && isValid(s.substr(idx, 2))){
            solve(idx+2, part+1, curr+s.substr(idx, 2)+".", ans, s);

        }

        if(idx+3 <= n && isValid(s.substr(idx, 3))){
            solve(idx+3, part+1, curr+s.substr(idx, 3)+".", ans, s);
        }
    }

    vector<string> restoreIpAddresses(string s) {
        vector<string> ans;
        string curr = "";
        int part  = 0;
        solve(0, part, curr, ans, s);

        return ans;
    }
};