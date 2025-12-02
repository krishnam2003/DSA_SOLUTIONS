class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int ps = 0;
        int mi = 0;
        int mx = 0;
        for(int i: nums){
            ps+=i;
            if(mi > ps) mi = ps;
            if(mx < ps) mx = ps;
        }
        if(mx == mi) return abs(mi);
        return abs(mi-mx);
    }
};