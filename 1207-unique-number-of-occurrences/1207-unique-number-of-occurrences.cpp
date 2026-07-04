class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int, int> freq_map;
        unordered_set<int> count_set;
        for(int i=0; i<arr.size(); i++){
            freq_map[arr[i]]++;
        }

        for(auto &it : freq_map){
            int freq = it.second;
            if(count_set.find(freq) != count_set.end()){
                return false;
            }
            count_set.insert(freq);
        }

        return true;
    }
};