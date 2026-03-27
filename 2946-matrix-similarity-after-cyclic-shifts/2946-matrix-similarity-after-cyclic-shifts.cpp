class Solution {
public:
    bool areSimilar(vector<vector<int>>& mat, int k) {
        int m = mat.size();
        int n = mat[0].size();
        
        int shift = k % n;
        
        for (int i = 0; i < m; i++) {
            vector<int> shifted(n);
            
            for (int j = 0; j < n; j++) {
                if (i % 2 == 0) {
                    // left shift
                    shifted[j] = mat[i][(j + shift) % n];
                } else {
                    // right shift
                    shifted[j] = mat[i][(j - shift + n) % n];
                }
            }
            
            // compare with original row
            if (shifted != mat[i]) return false;
        }
        
        return true;
    }
};