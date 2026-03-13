class Solution {
public:
    long long maxHeight(long long T, int t) {
        long long val = (2.0 * T) / t;
        long long x = (sqrt(1 + 4 * val) - 1) / 2;
        return x;
    }

    long long minNumberOfSeconds(int mountainHeight, vector<int>& workerTimes) {
        long long left = 0, right = 1e18;
        long long ans = right;

        while (left <= right) {
            long long mid = (left + right) / 2;

            long long total = 0;
            for (int t : workerTimes) {
                long long x = (sqrt(1 + 8.0 * mid / t) - 1) / 2;
                total += x;
                if (total >= mountainHeight) break;
            }

            if (total >= mountainHeight) {
                ans = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }

        return ans;
    }
};