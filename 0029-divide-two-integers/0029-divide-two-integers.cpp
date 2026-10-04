class Solution {
public:
    int divide(int dividend, int divisor) {

        // Overflow case
        if (dividend == INT_MIN && divisor == -1) {
            return INT_MAX;
        }

        // Determine sign
        bool negative = (dividend < 0) ^ (divisor < 0);

        // Convert to long long to safely handle INT_MIN
        long long a = llabs((long long)dividend);
        long long b = llabs((long long)divisor);

        long long quotient = 0;

        while (a >= b) {

            long long temp = b;
            long long multiple = 1;

            // Find the largest doubled divisor <= dividend
            while (a >= (temp << 1)) {
                temp <<= 1;
                multiple <<= 1;
            }

            // Subtract it
            a -= temp;

            // Add its corresponding quotient
            quotient += multiple;
        }

        if (negative) {
            quotient = -quotient;
        }

        return (int)quotient;
    }
};