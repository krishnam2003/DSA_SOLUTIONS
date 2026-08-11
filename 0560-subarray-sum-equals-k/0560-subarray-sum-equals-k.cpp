class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        int count = 0;
        unordered_map<int, int> mp;
        mp[0] = 1;
        int prefixSum = 0;

        for(int num : nums){
            prefixSum = prefixSum + num;
            if(mp.find(prefixSum-k) != mp.end()){
                count = count + mp[prefixSum-k]; 
            }
            mp[prefixSum]++;
        }
        return count;

        
    }
};