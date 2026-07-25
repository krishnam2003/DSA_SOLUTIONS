class Solution {
public:
    int maxProduct(int n) {
        int maximum = 0;
        int secondMax = 0;
        while(n!=0){
            int digit = n%10;
            if(digit>maximum){
                secondMax = maximum;
                maximum = digit;
            }
            else if(digit > secondMax){
                secondMax = digit;
            }
            n = n/10;
        }

        return maximum*secondMax;
    }
};