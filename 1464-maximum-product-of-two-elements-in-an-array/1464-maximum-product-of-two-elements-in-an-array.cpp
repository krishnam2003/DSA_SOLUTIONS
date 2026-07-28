class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int largest = INT_MIN;
        int secLargest = INT_MIN;
        for(int i=0; i<n; i++){
            if(nums[i]>largest){
                secLargest = largest;
                largest = nums[i];
            }
            else if(nums[i] > secLargest && nums[i] <= largest){
                secLargest = nums[i];
            }
        }

        return (largest-1)*(secLargest-1);
    }
};