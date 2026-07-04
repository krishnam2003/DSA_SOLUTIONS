// class Solution {
// public:
//     bool uniqueOccurrences(vector<int>& arr) {
//         unordered_map<int, int> freq_map;
//         unordered_set<int> count_set;
//         for(int i=0; i<arr.size(); i++){
//             freq_map[arr[i]]++;
//         }

//         for(auto &it : freq_map){
//             int freq = it.second;
//             if(count_set.find(freq) != count_set.end()){
//                 return false;
//             }
//             count_set.insert(freq);
//         }

//         return true;
//     }
// };


class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        vector<int> vec(2001, 0);
        for(int &x : arr){
            vec[1000+x]++;
        }

        sort(begin(vec), end(vec));
        for(int i=1; i<2001; i++){
            if(vec[i] != 0 && vec[i] == vec[i-1]){
                return false;
            }
        }

        return true;
    }
};