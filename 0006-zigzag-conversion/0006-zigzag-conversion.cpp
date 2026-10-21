class Solution {
public:
    string convert(string s, int numRows) {
        // Edge case
        if (numRows == 1 || s.size() <= numRows)
            return s;

        vector<string> rows(numRows);

        int i = 0;

        while(i < s.size()){
            for (int index = 0; index < numRows && i < s.size(); index++) {
                rows[index] += s[i++];
                
            }

            for(int index = numRows-2; index > 0 && i < s.size(); index--){
                rows[index] += s[i++];
            }
        }


        string result;
        for (string &row : rows)
            result += row;

        return result;
    }
};