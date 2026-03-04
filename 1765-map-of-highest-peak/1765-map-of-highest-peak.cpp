// important multisource bfs question

#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        int m = isWater.size();
        int n = isWater[0].size();
        
        vector<vector<int>> height(m, vector<int>(n, -1));
        queue<pair<int,int>> q;
        
        // Step 1: Push all water cells into queue
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(isWater[i][j] == 1) {
                    height[i][j] = 0;
                    q.push({i, j});
                }
            }
        }
        
        // 4 directions
        int dir[4][2] = {{1,0}, {-1,0}, {0,1}, {0,-1}};
        
        // Step 2: BFS
        while(!q.empty()) {
            auto [x, y] = q.front();
            q.pop();
            
            for(int d = 0; d < 4; d++) {
                int nx = x + dir[d][0];
                int ny = y + dir[d][1];
                
                // Check boundaries
                if(nx >= 0 && nx < m && ny >= 0 && ny < n && height[nx][ny] == -1) {
                    height[nx][ny] = height[x][y] + 1;
                    q.push({nx, ny});
                }
            }
        }
        
        return height;
    }
};

// O(m × n) tc