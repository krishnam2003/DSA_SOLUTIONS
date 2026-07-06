class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        // unordered_map<int, int> freq;
        // for(auto &x : nums1){
        //     freq[x]++;
        // }
        // vector<int> result;
        // for(int i=0; i<nums2.size(); i++){
        //     int el = nums2[i];
        //     if(freq[el] > 0){
        //         freq[el]--;
        //         result.push_back(el);
        //     }
        // }

        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        vector<int> result;
        int i=0, j=0;
        while(i<nums1.size() && j<nums2.size()){
            if(nums1[i] == nums2[j]){
                result.push_back(nums1[i]);
                int val = nums1[i];
                while(i < nums1.size() && nums1[i] == val) i++;
                while(j < nums2.size() && nums2[j] == val) j++;
            }
            else if(nums1[i] < nums2[j]){
                i++;
            }
            else if(nums1[i] > nums2[j]){
                j++;
            }
        }

        return result;
    }
};