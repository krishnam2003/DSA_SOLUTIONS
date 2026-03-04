#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> onesMinusZeros(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<int> onesRow(m, 0);
        vector<int> onesCol(n, 0);

        // Count ones
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == 1) {
                    onesRow[i]++;
                    onesCol[j]++;
                }
            }
        }

        vector<vector<int>> diff(m, vector<int>(n));

        // Compute result
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                int zerosRow = n - onesRow[i];
                int zerosCol = m - onesCol[j];

                diff[i][j] = onesRow[i] + onesCol[j] 
                           - zerosRow - zerosCol;
            }
        }

        return diff;
    }
};

// diff[i][j] =
// 2 * onesRow[i]
// + 2 * onesCol[j]
// - m - n