class Solution {
public:
    int majorityElement(vector<int>& nums) {
        // hashmap approach

        // unordered_map<int, int> map;
        // int n = nums.size();
       
        // for(int num : nums){
        //     map[num]++;

        //     if(map[num]>n/2){
        //         return num;
        //     }
        // }
        // return -1;

        //moore-voting-algorithm

        int n = nums.size();
        int candidate = 0;  //int candidate = nums[0];
        int cnt = 0;  //int cnt = 1;
        for(int i=0; i<n; i++){         // i=1;
            if(cnt == 0){
                candidate = nums[i];
                cnt = 1;
            }
            else if(candidate == nums[i]){
                cnt++;
            }
            else{
                cnt--;
            }
        }
        return candidate;
    }
};