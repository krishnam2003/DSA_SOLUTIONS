class Solution {
public:
    string smallestSubsequence(string s) {
        vector<int> last(26, -1);

        // Store last occurrence of every character
        for (int i = 0; i < s.size(); i++) {
            last[s[i] - 'a'] = i;
        }

        string st;
        vector<bool> visited(26, false);

        for (int i = 0; i < s.size(); i++) {
            char c = s[i];

            // Already present in answer
            if (visited[c - 'a']) {
                continue;
            }

            // Remove larger characters if they occur again later
            while (!st.empty() &&
                   st.back() > c &&
                   last[st.back() - 'a'] > i) {

                visited[st.back() - 'a'] = false;
                st.pop_back();
            }

            st.push_back(c);
            visited[c - 'a'] = true;
        }

        return st;
    }
};