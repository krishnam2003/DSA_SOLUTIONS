class Solution {
public:
    void dfs(int n, string &curr, vector<string> &res) {
        if(curr.size() == n){
            res.push_back(curr);
            return;
        }

        for(char c : {'a','b','c'}){
            if(curr.empty() || curr.back() != c){
                curr.push_back(c);
                dfs(n, curr, res);
                curr.pop_back();
            }
        }
    }

    string getHappyString(int n, int k) {
        vector<string> res;
        string curr = "";

        dfs(n, curr, res);

        if(k > res.size()) return "";
        return res[k-1];
    }
};