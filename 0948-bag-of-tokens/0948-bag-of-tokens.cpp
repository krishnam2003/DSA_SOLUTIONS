class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        int n = tokens.size();

        sort(tokens.begin(), tokens.end());

        if(n == 0) return 0;

        int left = 0;
        int right = n-1;
        int maxScore = INT_MIN;

        int score = 0;

        while(left <= right){
            if(power >= tokens[left]){
                power = power - tokens[left];
                score++;

                maxScore = max(score, maxScore);
                left++;
            }
            else if(score >= 1){
                power = power + tokens[right];
                score--;

                right--;
            }
            else{
                return 0;
            }
        }

        return maxScore;
        
    }
};