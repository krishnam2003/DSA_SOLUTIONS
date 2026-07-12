class Solution {
public:
    string baseNeg2(int n) {
        if (n == 0) return "0";
        string ans;
        while(n != 0){
            int remainder = n%-2;
            n = n/-2;
            

            if(remainder < 0){
                remainder += 2;
                n++;
            }
            ans.push_back(remainder + '0');
        }

        reverse(ans.begin(), ans.end());

        return ans;
    }
};