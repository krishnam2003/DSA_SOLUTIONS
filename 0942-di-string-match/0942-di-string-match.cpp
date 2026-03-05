class Solution {
public:
    vector<int> diStringMatch(string s) {
        int low = 0, high = s.size();
        vector<int> ans;

        for(char c : s){
            if(c == 'I'){
                ans.push_back(low++);
            }else{
                ans.push_back(high--);
            }
        }

        ans.push_back(low);
        return ans;
    }
};