class Solution {
public:
    char processStr(string s, long long k) {
        int n = s.size();

        vector<long long> len(n + 1, 0);

        for (int i = 0; i < n; i++) {
            char ch = s[i];

            if ('a' <= ch && ch <= 'z') {
                len[i + 1] = len[i] + 1;
            }
            else if (ch == '*') {
                len[i + 1] = max(0LL, len[i] - 1);
            }
            else if (ch == '#') {
                len[i + 1] = len[i] * 2;
            }
            else { // '%'
                len[i + 1] = len[i];
            }
        }

        if (k >= len[n]) return '.';

        long long pos = k;

        for (int i = n - 1; i >= 0; i--) {
            char ch = s[i];

            long long before = len[i];
            long long after  = len[i + 1];

            if ('a' <= ch && ch <= 'z') {
                if (pos == after - 1) return ch;
            }
            else if (ch == '#') {
                if (before > 0)
                    pos %= before;
            }
            else if (ch == '%') {
                if (before > 0)
                    pos = before - 1 - pos;
            }
            // '*' -> pos unchanged
        }

        return '.';
    }
};