class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();

        vector<vector<int>> visited(n, vector<int>(m, 0));
        vector<vector<int>> dist(n, vector<int>(m, 0));

        queue<pair<pair<int, int>, int>> q;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(mat[i][j] == 0){
                    q.push({{i, j}, 0});
                    visited[i][j] = 1;
                }
                else{
                    visited[i][j] = 0;
                }
            }
        }

       

        while(!q.empty()){
            int r = q.front().first.first;
            int c = q.front().first.second;
            int step = q.front().second;
            q.pop();
            dist[r][c] = step;

            vector<int> dx = {-1, 0, 1, 0};
            vector<int> dy = {0, 1, 0, -1};

            for(int i=0; i<4; i++){
                int nrow = dx[i] + r;
                int ncol = dy[i] + c;

                if(nrow >=0 && ncol >= 0 && nrow < n && ncol < m && mat[nrow][ncol] == 1 && visited[nrow][ncol] == 0){
                    q.push({{nrow, ncol}, step+1});
                    visited[nrow][ncol] = 1;
                }
            }
        }

        return dist;
        
    }
};