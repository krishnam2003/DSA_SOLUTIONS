// class Solution {
// public:
//     int fib(int n) {
//         vector<int> dp(n+1, -1);  // bottom up sc -> O(n);
//         if(n <= 1){               // tc -> O(n);
//             return n;
//         }

//         dp[0] = 0;
//         dp[1] = 1;
//         for(int i=2; i<n+1; i++){
//             dp[i] = dp[i-1] + dp[i-2];
//         }

//         return dp[n];
//     }
// };


class Solution {
public:
    int fib(int n) {
        //vector<int> dp(n+1, -1);  // bottom up sc -> O(n);
        if(n <= 1){               // tc -> O(n);
            return n;
        }

        int a = 0;
        int b = 1;
        int c;
        for(int i=1; i<n; i++){
            c = a+b;
            a = b;
            b = c;
        }

        return c;
    }
};