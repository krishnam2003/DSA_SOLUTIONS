class Solution {
public:

    double isPossible(vector<int>& piles, int h, int mid){
        double totalH = 0;
        for(int i=0; i<piles.size(); i++){
            totalH += (piles[i] + mid - 1)/mid;
        }
        return totalH;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int largest  = piles[0];
        for(int i=0; i<piles.size(); i++){
            if(piles[i] > piles[0]){
                largest = piles[i];
            }
        }
        int low  = 1;
        int high = largest;

        while(low <= high){
            int mid  = low + (high-low)/2;
            double totalHours  = isPossible(piles, h, mid);
            if(totalHours <= h){
                high  = mid - 1;
            }
            else{
                low  = mid + 1;
            }
        }

        return low;

    }
};