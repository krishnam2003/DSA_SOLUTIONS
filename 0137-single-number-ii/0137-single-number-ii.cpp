class Solution {
public:
    int singleNumber(vector<int>& nums) {
        // map<int, int> mp;
        // for(int & x : nums){
        //     mp[x]++;
        // }

        // for(auto &it : mp){
        //     if(it.second == 1){           //brute force
        //         return it.first;
        //     }
        // }

        // return -1;

        int result = 0;
        for(int k=0; k<=31; k++){
            int countOnes = 0;
            int countZeroes = 0;
            for(int &num : nums){
                if((num & (1 << k)) != 0){
                    countOnes++;
                }
                else{
                    countZeroes++;
                }
            }

            if(countOnes % 3 == 1){
                result = result | (1 << k);
            }
        }

        return result;
    }
};