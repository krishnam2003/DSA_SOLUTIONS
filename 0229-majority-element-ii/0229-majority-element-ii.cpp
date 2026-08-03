class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        // unordered_map<int, int> elementCounter;
        
        // for(int i=0; i<n; i++){
        //     elementCounter[nums[i]]++;
        // }

        // vector<int> majorityElement;
        // int threshold = n/3;

        // for(auto countElement : elementCounter){
        //     int element = countElement.first;
        //     int cnt = countElement.second;

        //     if(cnt>threshold){
        //         majorityElement.push_back(element);
        //     }
        // }

        

        // return majorityElement;

        int count1 = 0;
        int count2 = 0;
        int candidate1 = 0;
        int candidate2 = 0;

        for(int i=0; i<n; i++){
            if(count1 == 0 && candidate2 != nums[i]){
                count1 = 1;
                candidate1 = nums[i];
            }
            else if(count2 == 0 && candidate1 != nums[i]){
                count2 = 1;
                candidate2 = nums[i];
            }
            else if(candidate1 == nums[i]){
                count1++;
            }
            else if(candidate2 == nums[i]){
                count2++;
            }
            else{
                count1--;
                count2--;
            }
        }

        int threshold = n/3;
        vector<int>majorityElement;

        count1 = 0;
        count2 = 0;

        for(int i=0; i<n; i++){
            if(candidate1 == nums[i]){
                count1++;
            }
            else if(candidate2 == nums[i]){
                count2++;
            }
        }

        if(count1>threshold){
            majorityElement.push_back(candidate1);

        }
        if(count2>threshold){
            majorityElement.push_back(candidate2);
        }

        return majorityElement;
    }
};