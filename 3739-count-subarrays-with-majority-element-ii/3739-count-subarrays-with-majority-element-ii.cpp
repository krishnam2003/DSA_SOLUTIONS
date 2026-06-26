class Solution {
public:
    class Fenwick {
    public:
        vector<int> bit;
        int n;

        Fenwick(int size) {
            n = size;
            bit.assign(n + 1, 0);
        }

        void update(int idx, int val) {
            while (idx <= n) {
                bit[idx] += val;
                idx += idx & -idx;
            }
        }

        int query(int idx) {
            int sum = 0;
            while (idx > 0) {
                sum += bit[idx];
                idx -= idx & -idx;
            }
            return sum;
        }
    };

    long long countMajoritySubarrays(vector<int>& nums, int target) {

        int n = nums.size();

        // Prefix sums after transforming:
        // target -> +1
        // others -> -1
        vector<int> prefix(n + 1, 0);

        for (int i = 0; i < n; i++) {
            prefix[i + 1] = prefix[i] + (nums[i] == target ? 1 : -1);
        }

        // Coordinate Compression
        vector<int> values = prefix;
        sort(values.begin(), values.end());
        values.erase(unique(values.begin(), values.end()), values.end());

        Fenwick ft(values.size());

        long long ans = 0;

        for (int x : prefix) {

            int idx = lower_bound(values.begin(), values.end(), x) - values.begin() + 1;

            // Count previous prefix sums < current prefix sum
            ans += ft.query(idx - 1);

            // Insert current prefix sum
            ft.update(idx, 1);
        }

        return ans;
    }
};