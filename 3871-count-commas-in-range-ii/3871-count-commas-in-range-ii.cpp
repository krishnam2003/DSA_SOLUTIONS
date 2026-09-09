class Solution {
public:
    long long countCommas(long long n) {
        long long ans = 0;

        // First comma starts at 1000
        long long start = 1000;
        long long commas = 1;

        while (start <= n) {
            // Numbers having at least this many commas
            ans += n - start + 1;

            // Move to the next comma level
            start *= 1000;
            commas++;
        }

        return ans;
    }
};