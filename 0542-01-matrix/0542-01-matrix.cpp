class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size(), dr[] = {0, 0, 1, -1}, dc[] = {1,-1,0,0};
        vector<vector<int>> ans(m, vector<int>(n, 0));
        queue<pair<int, int>>q;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(mat[i][j] == 0) {
                    
                    q.push({i, j});
                }
                else ans[i][j]=1e9;
            }
        }

        while(!q.empty()){
            int r = q.front().first, c = q.front().second;
            q.pop();
            for(int i=0;i<4;i++){
                int nr = r + dr[i], nc = c + dc[i];
                if(nr>=0 && nr<m && nc>= 0 && nc<n){
                    if(1+ans[r][c] < ans[nr][nc]) {
                        ans[nr][nc] = 1 + ans[r][c];
                        q.push({nr, nc});
                    }
                }
            }
        }
        return ans;
    }
};