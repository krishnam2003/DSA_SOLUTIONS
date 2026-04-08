class Solution {
public:
    int hammingDistance(int x, int y) {
        int xorVal = x ^ y;
        int cnt = 0;
        while(xorVal){
            cnt = cnt + (xorVal & 1);
            xorVal = xorVal >> 1;

        }
        return cnt;
    }
};