class Solution {
public:
    bool checkDivisibility(int n) {
        int realNum  = n;
        int sum = 0;
        int product  = 1;
        while(n >0){
            int digit = n%10;
            sum = sum + digit;
            product  = product * digit;
            n /= 10;
        }

        int total = sum + product;

        if(realNum % total == 0) return true;

        return false;
    }
};