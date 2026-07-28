class Solution {
public:

    bool findWord(vector<vector<char>>& board, int i, int j, int idx, string& word){
        int m = board.size();
        int n = board[0].size();
        
        if(idx == word.size()) return true;
        if(i<0 || j<0 || i>=m || j>=n || board[i][j] == '$') return false;
        if(board[i][j] != word[idx]) return false;
      
        char temp = board[i][j];;
        board[i][j] = '$';
        int dx[] = {1,0,0,-1};
        int dy[] = {0,-1,1,0};
        for(int k=0; k<4; k++){
            int nR = i + dx[k];
            int nC = j + dy[k];

            
            if(findWord(board, nR, nC, idx+1, word)){
                board[i][j] = temp;
                return true;
            }
            
        }
        board[i][j] = temp;
        return false;
    }

    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();
        int idx = 0;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(board[i][j] == word[0] && findWord(board, i, j, 0, word)){
                    return true;
                }
            }
        }

        return false;
    }
};