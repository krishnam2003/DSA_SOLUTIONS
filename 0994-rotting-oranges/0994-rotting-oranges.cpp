class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        int time = 0;
        queue<pair<pair<int, int>, int>> q;
        vector<vector<int>> visited(n, vector<int>(m, 0));

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j] == 2){
                    q.push({{i,j},0});
                    visited[i][j] = 2;
                }
            }
        }

        
        int dx[4] = {-1, 0, 1, 0};
        int dy[4] = {0, 1, 0, -1};
        while(!q.empty()){
            int r = q.front().first.first;
            int c = q.front().first.second;
            int t = q.front().second;
            time = max(time, t);
            q.pop();

            for(int i=0; i<4; i++){
                int nRow = r + dx[i];
                int nCol = c + dy[i];
                if(nRow >= 0 && nRow < n && nCol >= 0 && nCol < m && visited[nRow][nCol] != 2 && grid[nRow][nCol] == 1 ){
                    q.push({{nRow, nCol}, t+1});
                    visited[nRow][nCol] = 2;
                }
            }

           
        }
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(visited[i][j] != 2 && grid[i][j] == 1){
                    return -1;
                }
                    
            }
        }
        return time;
    }
};