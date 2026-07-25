class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size();
        int left = 0;
        int right = n-1;
        int maxN = 0;
        vector<int> arr(n);
        for(int i=n-1; i>=0; i--){
            int rightSquare = nums[right]*nums[right];
            int leftSquare = nums[left]*nums[left];
            if(rightSquare >= leftSquare){
                arr[i] = rightSquare;
                right--;
            }
            else{
                arr[i] = leftSquare;
                left++;
            }
        }

        return arr;
    }
};