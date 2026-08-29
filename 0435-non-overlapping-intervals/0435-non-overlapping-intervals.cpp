class Solution {
public:

    static bool compare(const vector<int> &a, const vector<int> &b){
        if(a[1] == b[1]) return a[0] < b[0];
        return a[1] < b[1];
    };

    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();
        
        sort(intervals.begin(), intervals.end(), compare);
        
        int cnt = 0;
        int take  = intervals[0][1];
        
        for(int i=1; i<n; i++){
            if(intervals[i][0] >= take){
                take  = intervals[i][1];
            }
            else{
                cnt++;
            }
        }
        
        return cnt;
    }
};