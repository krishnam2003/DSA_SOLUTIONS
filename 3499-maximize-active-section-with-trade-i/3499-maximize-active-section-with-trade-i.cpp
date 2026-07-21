class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        int n = s.size();
        vector<int> zeroBlock;
        int cnt = 0;
        int Ones = 0;
        for(auto & x : s){
            if(x == '1'){
                Ones++;
            }
            else{
                cnt++;
            }
            if(x == '1' && cnt > 0){
                zeroBlock.push_back(cnt);
                cnt = 0;
            }
        }
        if(cnt > 0){
            zeroBlock.push_back(cnt);
        }
        int maxi = 0;
        for(int i=0; i+1<zeroBlock.size(); i++){
            int activeS = zeroBlock[i]+zeroBlock[i+1];
            maxi = max(maxi, activeS);
        }

        return maxi+Ones;
    }
};