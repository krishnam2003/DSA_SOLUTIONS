class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(), pairs.end(), [](const vector<int>& a, const vector<int>& b){
            return a[1] < b[1];
        }); // it is used whenever we want to sort the 2D array on the basis of the 
            //index just keep write there index num and < & > for ascending and descending 
            // order.

        if(pairs.size() == 0){
            return 0;
        }

        int end = pairs[0][1];
        int count = 1;

        int n = pairs.size();
        for(int i=1; i<n; i++){
            if(pairs[i][0] > end){
                count = count + 1;
                end = pairs[i][1];
            }
        }

        return count;
    }
};