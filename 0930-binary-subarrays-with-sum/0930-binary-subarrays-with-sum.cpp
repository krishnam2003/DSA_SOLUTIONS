class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int n = nums.size();
        unordered_map<int, int> mp;

        int prefixSum = 0;
        int cnt = 0;
        mp[0] = 1;

        for(int i=0; i<n; i++){
            prefixSum += nums[i];

            if(mp.find(prefixSum - goal) != mp.end()){
                cnt += mp[prefixSum - goal];
            }

            mp[prefixSum]++;
        }

        return cnt;

    }
};