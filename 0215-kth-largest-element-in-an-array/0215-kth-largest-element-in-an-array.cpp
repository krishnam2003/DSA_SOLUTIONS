class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int size = nums.size();
        priority_queue<int, vector<int>, greater<int>> minH;

        for(int i=0; i<size; i++){
            minH.push(nums[i]);
            if(minH.size() > k){
                minH.pop();
            }
        }

        return minH.top();
    }
};