class Solution {
public:
    int minOperations(string s) {
        int n = s.length();
        int pattern1 = 0, pattern2 = 0;

        for(int i = 0; i < n; i++) {
            char expected1 = (i % 2 == 0) ? '0' : '1'; // 010101
            char expected2 = (i % 2 == 0) ? '1' : '0'; // 101010

            if(s[i] != expected1) pattern1++;
            if(s[i] != expected2) pattern2++;
        }

        return min(pattern1, pattern2);
    }
};