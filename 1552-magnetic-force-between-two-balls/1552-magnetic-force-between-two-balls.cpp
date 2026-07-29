class Solution {
public:
    
    bool isPossible(vector<int>& position, int m, int dist){
        int ballPlaced = 1;
        int lastPos = position[0];

        for(int i=1; i<position.size(); i++){
            if(position[i]-lastPos >= dist){
                ballPlaced++;
                lastPos = position[i];

                if(ballPlaced == m){
                    return true;
                }
            }
        }

        return false;
    }

    int maxDistance(vector<int>& position, int m) {
        sort(position.begin(), position.end());
        int low = 1;
        int high = position.back()-position.front();
        while(low <= high){
            int mid = low + (high-low)/2;
            if(isPossible(position, m, mid)){
                low = mid + 1;
            }
            else{
                high  = mid - 1;
            }
        }

        return high;
    }
};