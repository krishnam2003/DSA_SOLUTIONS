class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int size = gain.size();
        vector<int> prefix(size);
        prefix[0] = gain[0];
        for(int i=1; i<size; i++){
            prefix[i] = prefix[i-1] + gain[i];
        }

        int mx = 0;
        for(int i : prefix){
            mx = max(mx, i);
        }

        return mx;
    }
};