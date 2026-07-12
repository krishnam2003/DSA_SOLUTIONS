class Solution {
public:
    int minBitFlips(int start, int goal) {
        int n = start ^ goal;
        // and then count the set bits of n 
        int cntBits = 0;
        while(n != 0){
            n  = n & (n - 1);
            cntBits++;
        }

        return cntBits;
    }
};