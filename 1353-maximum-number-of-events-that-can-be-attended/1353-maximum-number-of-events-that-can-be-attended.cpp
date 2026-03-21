class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
        
        sort(events.begin(), events.end()); // ✅ sort by start day
        
        priority_queue<int, vector<int>, greater<int>> pq; // ✅ min heap
        
        int day = 0, i = 0, count = 0;
        int n = events.size();
        
        while (i < n || !pq.empty()) {
            
            // If no active events → jump to next start day
            if (pq.empty()) {
                day = events[i][0];
            }

            // Add all events starting today
            while (i < n && events[i][0] == day) {
                pq.push(events[i][1]);
                i++;
            }

            // Remove expired events
            while (!pq.empty() && pq.top() < day) {
                pq.pop();
            }

            // Attend one event
            if (!pq.empty()) {
                pq.pop();
                count++;
            }

            day++;
        }
        
        return count;
    }
};