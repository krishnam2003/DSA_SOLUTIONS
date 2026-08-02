class Solution {
public:
    int compress(vector<char>& chars) {
        int n = chars.size();
        int index = 0;
        int i = 0;

        while(i<n){
            char currChar = chars[i];
            int cnt = 0;

            while(i<n && currChar == chars[i]){
                cnt++;
                i++;
            }

            chars[index] = currChar;
            index++;
            if(cnt > 1){
                string cnt_str = to_string(cnt);
                for(auto &ch : cnt_str){
                    chars[index] = ch;
                    index++;
                }
                
            }
        }

        return index;
    }
};