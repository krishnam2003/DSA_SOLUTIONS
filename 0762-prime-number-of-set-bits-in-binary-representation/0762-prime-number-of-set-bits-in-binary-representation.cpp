class Solution {
public:
    bool isPrime(int n){
        if(n < 2) return false;
        for(int i=2; i*i <= n; i++){
            if(n%i == 0){
                return false;
            }
        }

        return true;
    }

    int countPrimeSetBits(int left, int right) {
        int cntPrime = 0;
        for(int i = left; i<=right; i++){
            int cnt = 0 ;
            int num = i;
            while(num != 0){
                num = num & num-1;
                cnt++;
            }
            

            if(isPrime(cnt)){
                cntPrime++;
            }
        }

        return cntPrime;
    }
};