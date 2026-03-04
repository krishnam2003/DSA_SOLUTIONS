#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        
        int m = mat.size();
        int n = mat[0].size();
        
        // Check if reshape possible
        if(m * n != r * c)
            return mat;
        
        vector<vector<int>> result(r, vector<int>(c));
        
        int index = 0;
        
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                
                result[index / c][index % c] = mat[i][j];
                index++;
            }
        }
        
        return result;
    }
};

// vector<vector<int>> result(r, vector<int>(c));
// this creates
// result = [ _  _  _  _ ]
// (1 row, 4 columns)