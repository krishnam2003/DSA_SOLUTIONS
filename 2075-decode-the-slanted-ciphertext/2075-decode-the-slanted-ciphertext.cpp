#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string decodeCiphertext(string encodedText, int rows) {
        if (rows == 1) return encodedText;

        int n = encodedText.size();
        int cols = n / rows;

        string result = "";

        // Traverse diagonally
        for (int c = 0; c < cols; c++) {
            int r = 0, j = c;

            while (r < rows && j < cols) {
                result += encodedText[r * cols + j];
                r++;
                j++;
            }
        }

        // Remove trailing spaces
        while (!result.empty() && result.back() == ' ') {
            result.pop_back();
        }

        return result;
    }
};