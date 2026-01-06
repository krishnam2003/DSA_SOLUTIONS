class Solution {
public:

    void dfs(int row, int col, vector<vector<char>>& board, vector<vector<int>>& visited, vector<int>dx, vector<int>dy){
        int n = board.size();
        int m = board[0].size();
        visited[row][col] = 1;
        for(int k=0; k<4; k++){
            int nRow = row + dx[k];
            int nCol = col + dy[k];

            if(nRow>=0 && nCol>=0 && nRow<n && nCol<m && !visited[nRow][nCol] && board[nRow][nCol] == 'O'){
                dfs(nRow, nCol, board, visited, dx, dy);
            }
        }

        
    }

    void solve(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();

        //if(n==0 || m==0) return board;

        vector<vector<int>> visited(n, vector<int>(m, 0));

        vector<int> dx = {-1, 0, 1, 0};
        vector<int> dy = {0, 1, 0, -1};

        for(int i=0; i<n; i++){
            if(!visited[i][0] && board[i][0] == 'O'){
                dfs(i, 0, board, visited, dx, dy);
            }
            if(!visited[i][m-1] && board[i][m-1] == 'O'){
                dfs(i, m-1, board, visited, dx, dy);
            }
        }

        for(int j=0; j<m; j++){
            if(!visited[0][j] && board[0][j] == 'O'){
                dfs(0, j, board, visited, dx, dy);
            }
            if(!visited[n-1][j] && board[n-1][j] == 'O'){
                dfs(n-1, j, board, visited, dx, dy);
            }
        }

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(!visited[i][j] && board[i][j] == 'O'){
                    board[i][j] = 'X';
                }
            } 
        }
        
    }
};