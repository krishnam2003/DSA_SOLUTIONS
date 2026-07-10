class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        int top = 0;
        int right = n-1;
        int left = 0;
        int bottom = m-1;
        vector<int> vec;
        while(top <= bottom && left <= right){
            //top colomn
            for(int i=left; i<=right; i++){
                vec.push_back(matrix[top][i]);
            }
            top++;

            //right
            for(int i=top; i<=bottom; i++){
                vec.push_back(matrix[i][right]);
            }
            right--;

            //bottom
            if(top <= bottom){
                for(int i=right; i>=left; i--){
                    vec.push_back(matrix[bottom][i]);
                }
                bottom--;
            }
            //left
            if(left <= right){
                for(int i=bottom; i>=top; i--){
                    vec.push_back(matrix[i][left]);
                }
                left++;
            }
        }

        return vec;
    }
};