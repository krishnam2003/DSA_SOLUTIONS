class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char, int> freq1;
        for(char e : s){
            freq1[e]++;
        }

        unordered_map<char, int> freq2;
        for(char e : t){
            freq2[e]++;
        }

        if(freq1 == freq2){
            return true;
        }else{
            return false;
        }


    }
};