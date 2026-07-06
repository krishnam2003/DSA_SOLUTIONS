class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> freq;
        for(auto &x : nums1){
            freq[x]++;
        }
        vector<int> result;
        for(int i=0; i<nums2.size(); i++){
            int el = nums2[i];
            if(freq[el] > 0){
                freq[el]--;
                result.push_back(el);
            }
        }

        return result;
    }
};