class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        unordered_map<char, int> stone_cnt;
        for(auto c : stones){
            stone_cnt[c]++;
        }
        int count = 0;
        for(auto j : jewels){
            if(stone_cnt.find(j) != stone_cnt.end()){
                count += stone_cnt[j];
            }
        }

        return count;
    }
};