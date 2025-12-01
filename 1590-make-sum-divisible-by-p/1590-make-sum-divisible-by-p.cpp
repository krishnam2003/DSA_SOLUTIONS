class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        int n = nums.size();
        long long total_sum = 0;
        for (int num : nums) {
            total_sum += num;
        }
        int target_mod = total_sum % p;
        if (target_mod == 0) return 0;

        unordered_map<int, int> last_seen;
        last_seen[0] = -1; // prefix mod 0 at index -1
        int curr_prefix_mod = 0;
        int min_len = n;

        for (int i = 0; i < n; i++) {
            curr_prefix_mod = (curr_prefix_mod + nums[i]) % p;
            int needed = (curr_prefix_mod - target_mod + p) % p;
            
            if (last_seen.find(needed) != last_seen.end()) {
                int len = i - last_seen[needed];
                // Check if it's not removing the whole array
                if (len != n) {
                    min_len = min(min_len, len);
                }
            }
            last_seen[curr_prefix_mod] = i;
        }

        return (min_len == n) ? -1 : min_len;
    }
};