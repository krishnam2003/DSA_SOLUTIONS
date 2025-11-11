class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        int count = 0;
        unordered_map<int, int> sumCount;
        sumCount[0] = 1;
        int prefixSum = 0;
        for(int num : nums){
            prefixSum = prefixSum + num;
            if(sumCount.find(prefixSum-k) != sumCount.end()){
                count = count + sumCount[prefixSum-k]; 
            }
            sumCount[prefixSum]++;
        }
        return count;
        
    }
};