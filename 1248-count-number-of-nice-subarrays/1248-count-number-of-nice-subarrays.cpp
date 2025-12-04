class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        // Helper function: count subarrays with at most k odd numbers
        auto atMost = [&](int k) {
            if (k < 0) return 0;
            int left = 0, count = 0, oddCount = 0;
            
            for (int right = 0; right < nums.size(); right++) {
                if (nums[right] % 2 == 1) oddCount++;
                
                // Shrink window if oddCount exceeds k
                while (oddCount > k) {
                    if (nums[left] % 2 == 1) oddCount--;
                    left++;
                }
                
                // All subarrays ending at 'right' are valid
                count += (right - left + 1);
            }
            return count;
        };
        
        return atMost(k) - atMost(k - 1);
    }
};