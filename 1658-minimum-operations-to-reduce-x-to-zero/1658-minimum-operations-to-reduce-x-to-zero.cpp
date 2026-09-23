class Solution {
public:
    int minOperations(vector<int>& nums, int x) {

        int targetSum = 0;
        for(int num : nums){
            targetSum += num;
        }

        int target = targetSum - x;
        if(target == 0) return nums.size();

        if(target < 0) return -1;

        int left = 0;
        int maxLen = -1;

        int sum = 0;

        for(int right=0; right<nums.size(); right++){
            sum += nums[right];
            while(sum > target){
                sum -= nums[left];
                left++;
            }

            if(sum == target){
                maxLen = max(maxLen, right-left+1);
            }
        }
        if(maxLen == -1) return -1;

        return nums.size()-maxLen;
    }
};