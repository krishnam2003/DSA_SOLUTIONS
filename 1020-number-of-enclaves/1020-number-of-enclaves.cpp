class Solution {
public:

    void dfs(vector<vector<int>>& grid,
             vector<vector<int>>& visited,
             int row, int col) {

        int n = grid.size();
        int m = grid[0].size();

        visited[row][col] = 1;

        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};

        for(int i = 0; i < 4; i++) {

            int nr = row + dr[i];
            int nc = col + dc[i];

            if(nr >= 0 && nr < n &&
               nc >= 0 && nc < m &&
               grid[nr][nc] == 1 &&
               visited[nr][nc] == 0) {

                dfs(grid, visited, nr, nc);
            }
        }
    }

    int numEnclaves(vector<vector<int>>& grid) {

        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> visited(n, vector<int>(m, 0));

        // Start DFS from boundary 1s
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {

                if(i == 0 || j == 0 ||
                   i == n-1 || j == m-1) {

                    if(grid[i][j] == 1 &&
                       visited[i][j] == 0) {

                        dfs(grid, visited, i, j);
                    }
                }
            }
        }

        // Count remaining 1s
        int count = 0;

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {

                if(grid[i][j] == 1 &&
                   visited[i][j] == 0) {

                    count++;
                }
            }
        }

        return count;
    }
};