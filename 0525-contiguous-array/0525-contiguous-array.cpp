class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int n = nums.size();
        vector<int> arr(n);
        int maxLen = 0;
        for(int i=0; i<n; i++){
            if(nums[i] == 0){
                arr[i] = -1;
            }
            else{
                arr[i] = 1;
            }
        }

        unordered_map<int, int> mp;
        vector<int> prefix_sum(n,0);
        prefix_sum[0] = arr[0];
        for(int i=1; i<arr.size(); i++){
            prefix_sum[i] = prefix_sum[i-1] + arr[i];
        }
        mp[0] = -1;
        for(int i=0; i<prefix_sum.size(); i++){
            if(mp.find(prefix_sum[i]) != mp.end()){
                maxLen = max(maxLen, i - mp[prefix_sum[i]]);
            }
            else{
                mp[prefix_sum[i]] = i;
            }
            
        }

        return maxLen;
    }
};