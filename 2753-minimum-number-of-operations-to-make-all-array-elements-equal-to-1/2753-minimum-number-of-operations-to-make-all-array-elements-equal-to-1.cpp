class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        int num1 = 0;
        int g = 0;
        for(int x: nums){
            if(x == 1){
                num1++;
            }
            g = gcd(g, x);
        }
        if(num1 > 0){
            return n - num1;
        }

        if(g > 1){
            return -1;
        }   

        int minLen = n;
        for(int i = 0; i<n; i++){
            int g = 0;
            for(int j = i; j<n; j++){
                g = gcd(g, nums[j]);
                if(g == 1){
                    minLen = min(minLen, j-i+1);
                    break;
                }
            }
        }

        return (minLen-1+n-1);
    
    }
};