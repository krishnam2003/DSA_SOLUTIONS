class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int n = nums.size();
        int max_sum = 0, min_sum = 0;
        int curr_max = 0, curr_min = 0;
        
        for(int i = 0; i < n; i++) {
            // Maximum subarray sum (Kadane's)
            curr_max = max(nums[i], curr_max + nums[i]);
            max_sum = max(max_sum, curr_max);
            
            // Minimum subarray sum
            curr_min = min(nums[i], curr_min + nums[i]);
            min_sum = min(min_sum, curr_min);
        }
        
        // Maximum absolute sum is either max_sum or abs(min_sum)
        return max(max_sum, abs(min_sum));
    }
};