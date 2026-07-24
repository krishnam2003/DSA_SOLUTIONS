class Solution {
public:
    vector<int> getSubarrayBeauty(vector<int>& nums, int k, int x) {

        vector<int> ans;

        // Index 0 represents -50
        // Index 49 represents -1
        int freq[50] = {};

        int i = 0;
        int j = 0;

        while (j < nums.size()) {

            // Add current element to frequency array
            if (nums[j] < 0) {
                freq[nums[j] + 50]++;
            }

            // Window size is smaller than k
            if (j - i + 1 < k) {
                j++;
            }

            // Window size is exactly k
            else if (j - i + 1 == k) {

                int count = 0;
                int beauty = 0;

                // Find x-th smallest negative number
                int value = -50;

                while (value <= -1) {

                    count += freq[value + 50];

                    if (count >= x) {
                        beauty = value;
                        break;
                    }

                    value++;
                }

                ans.push_back(beauty);

                // Remove the leftmost element
                if (nums[i] < 0) {
                    freq[nums[i] + 50]--;
                }

                // Slide window
                i++;
                j++;
            }
        }

        return ans;
    }
};