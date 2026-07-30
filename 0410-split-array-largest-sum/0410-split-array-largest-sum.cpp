class Solution {
public:

    bool isPossible(vector<int>& nums, int k, int ans){
        int totalP = 0;
        int cnt = 0;
        for(int i=0; i<nums.size(); i++){
            if(totalP + nums[i] <= ans){
                totalP += nums[i];
            }
            else{
                cnt++;
                totalP = nums[i];
            }
        }

        return cnt<k;
    }

    int splitArray(vector<int>& nums, int k) {
        int low = *max_element(nums.begin(), nums.end());
        int high = accumulate(nums.begin(), nums.end(), 0);

        while(low <= high){
            int mid  = low + (high-low)/2;
            if(!isPossible(nums, k, mid)){
                low = mid+1;
            }else{
                high = mid-1;
            }
        }

        return low;
    }
};