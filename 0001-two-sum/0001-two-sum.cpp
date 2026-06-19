class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        unordered_map<int, int> mp;
        for(int i=0;i<n;i++){
            int needed_el = target - nums[i];
            if(mp.find(needed_el) != mp.end()){
                return {mp[needed_el],i};
            }
            mp[nums[i]] = i;
        }
        return {-1,-1};

        

        
    }
    
};