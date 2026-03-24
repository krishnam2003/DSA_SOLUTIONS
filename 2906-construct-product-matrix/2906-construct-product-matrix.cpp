class Solution {
public:
    vector<vector<int>> constructProductMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int mod = 12345;

        int size = n * m;
        vector<long long> arr;

        // Step 1: flatten matrix
        for (auto &row : grid) {
            for (auto &val : row) {
                arr.push_back(val % mod);
            }
        }

        // Step 2: prefix
        vector<long long> prefix(size, 1);
        for (int i = 1; i < size; i++) {
            prefix[i] = (prefix[i - 1] * arr[i - 1]) % mod;
        }

        // Step 3: suffix
        vector<long long> suffix(size, 1);
        for (int i = size - 2; i >= 0; i--) {
            suffix[i] = (suffix[i + 1] * arr[i + 1]) % mod;
        }

        // Step 4: result
        vector<vector<int>> result(n, vector<int>(m));
        int idx = 0;

        for (int i = 0; i < size; i++) {
            long long val = (prefix[i] * suffix[i]) % mod;
            result[idx / m][idx % m] = val;
            idx++;
        }

        return result;
    }
};