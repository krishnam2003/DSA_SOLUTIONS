class Solution {
public:

    // void bfs(int row, int col, vector<vector<int>>& visited, vector<vector<char>>& grid){
    //     int n = grid.size();
    //     int m = grid[0].size();

    //     visited[row][col] = 1;
    //     queue<pair<int, int>> q;
    //     q.push({row, col});
    //     while(!q.empty()){
    //         int row = q.front().first;
    //         int col = q.front().second;
    //         q.pop();

    //         vector<int> dx = {-1, 0, 1, 0};
    //         vector<int> dy = {0, 1, 0, -1};

    //         for(int i = 0; i<4; i++){
                
    //                 int nbrRow = row + dx[i];
    //                 int nbrCol = col + dy[i];

    //                 if(nbrRow >=0 && nbrRow < n && nbrCol >=0 && nbrCol < m && grid[nbrRow][nbrCol]== '1'  && !visited[nbrRow][nbrCol]){
    //                     visited[nbrRow][nbrCol] = 1;
    //                     q.push({nbrRow, nbrCol});
    //                 }
                
    //         }

    //     }
    // }


    void bfs(int row, int col, vector<vector<char>>& grid){
        int n = grid.size();
        int m = grid[0].size();

        
        grid[row][col] = '0';
        vector<int> dx = {-1, 0, 1, 0};
        vector<int> dy = {0, 1, 0, -1};

        for(int i = 0; i<4; i++){
                
            int nbrRow = row + dx[i];
            int nbrCol = col + dy[i];

            if(nbrRow >=0 && nbrRow < n && nbrCol >=0 && nbrCol < m && grid[nbrRow][nbrCol]== '1'){
                bfs(nbrRow, nbrCol, grid);
            }
                
            

        }
    }


    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        //vector<vector<int>> visited(n, vector<int>(m, 0));
        int count = 0;

        for(int row = 0; row<n; row++){
            for(int col = 0; col<m; col++){
                if(grid[row][col] == '1'){
                    count++;
                    bfs(row, col, grid);
                }
            }
        }
        return count;
    }
};