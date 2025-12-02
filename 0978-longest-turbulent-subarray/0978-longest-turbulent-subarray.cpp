
class Solution {
public:
    int maxTurbulenceSize(vector<int>& arr) {
        int n = arr.size();
        if (n == 1) return 1;
        
        int left = 0;
        int max_len = 1;
        int prev_compare = 0;
        
        for (int right = 1; right < n; right++) {
            int curr_compare = 0;
            if (arr[right] > arr[right - 1]) {
                curr_compare = 1;
            } else if (arr[right] < arr[right - 1]) {
                curr_compare = -1;
            }
            
            if (curr_compare == 0) {
                
                left = right;
            } else if (right == 1 || curr_compare * prev_compare != -1) {
                
                left = right - 1;
            }
            
          
            max_len = max(max_len, right - left + 1);
            prev_compare = curr_compare;
        }
        
        return max_len;
    }
};