class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int n  = nums.size();


        unordered_map<int, int> mp;
        mp[0] = 1;

        int cnt = 0;
        int prefixSum = 0;

        for(int i=0; i<n; i++){
            if(nums[i] % 2 == 1){
                prefixSum += 1;
            }
            

            if(mp.find(prefixSum - k) != mp.end()){
                cnt += mp[prefixSum - k];
            }

            mp[prefixSum]++;
        }

        return cnt;
    }
};