class Solution {
public:
    int numSub(string s) {
        int output = 0;
        int cnt = 0;
        int MOD = 1e9 + 7;
        for(int i=0; i<s.size(); i++){
            if(s[i] == '1'){
                cnt++;
                output = (output + cnt) % MOD;
            }
            
            if(s[i] == '0'){
                cnt = 0;
            }
        }

        return output;
    }
};