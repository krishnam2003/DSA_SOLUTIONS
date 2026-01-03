class Solution {
 
private:

    void dfs(int sr, int sc, vector<vector<int>>& image, vector<vector<int>>& ans, int color, vector<int> dRow, vector<int> dCol,  int iniColor){

        ans[sr][sc] = color;

        int n = image.size();
        int m = image[0].size();

        for(int i=0; i<4; i++){
            int nRow = sr + dRow[i];
            int nCol = sc + dCol[i];

            if(nRow>=0 && nRow<n && nCol>=0 && nCol<m && image[nRow][nCol] == iniColor && ans[nRow][nCol] != color){
                dfs(nRow, nCol, image, ans, color, dRow, dCol, iniColor);
            } 
        }
    }

  

public:

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        vector<vector<int>> ans = image;
        vector<int> dRow = {-1, 0, 1, 0};
        vector<int> dCol = {0, 1, 0, -1};

        int iniColor = image[sr][sc];

        dfs(sr, sc, image, ans, color, dRow, dCol, iniColor);

        return ans;
    }
};