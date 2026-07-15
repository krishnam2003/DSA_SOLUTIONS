class Solution {
public:

    int findMinElement(vector<int>& nums, int n){
        int l = 0, r = n-1;
        while(l < r){
            int mid = l + (r-l)/2;
            if(nums[mid] > nums[r]){
                l = mid+1;
            }
            else{
                r = mid;
            }
        }

        return nums[r];
    }

    int findMin(vector<int>& nums) {
        int n = nums.size();
        int min_element = findMinElement(nums, n);

        if(min_element != -1){
            return min_element;
        }

        return -1;
    }
};