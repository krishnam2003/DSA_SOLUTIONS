class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        
        unordered_set<string> obs;
        for (auto &o : obstacles) {
            obs.insert(to_string(o[0]) + "," + to_string(o[1]));
        }
        
        vector<int> dx = {0, 1, 0, -1};
        vector<int> dy = {1, 0, -1, 0};
        
        int x = 0, y = 0;
        int dir = 0; // North
        
        int maxDist = 0;
        
        for (int cmd : commands) {
            
            if (cmd == -1) { // right
                dir = (dir + 1) % 4;
            }
            else if (cmd == -2) { // left
                dir = (dir + 3) % 4;
            }
            else {
                for (int i = 0; i < cmd; i++) {
                    int nx = x + dx[dir];
                    int ny = y + dy[dir];
                    
                    string key = to_string(nx) + "," + to_string(ny);
                    
                    if (obs.count(key)) break;
                    
                    x = nx;
                    y = ny;
                    
                    maxDist = max(maxDist, x*x + y*y);
                }
            }
        }
        
        return maxDist;
    }
};