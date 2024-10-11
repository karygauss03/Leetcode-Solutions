class Solution {
public:
    int smallestChair(vector<vector<int>>& times, int targetFriend) {
        int n = times.size();
        
        vector<tuple<int, int, int>> events;
        for (int i = 0; i < n; ++i) {
            events.push_back({times[i][0], 1, i}); 
            events.push_back({times[i][1], -1, i});
        }

        sort(events.begin(), events.end());
        
        priority_queue<int, vector<int>, greater<int>> availableChairs;
        for (int i = 0; i < n; ++i) {
            availableChairs.push(i);
        }
        
        vector<int> occupiedChair(n, -1);
        
        for (const auto& event : events) {
            int time, type, friendIndex;
            tie(time, type, friendIndex) = event;
            
            if (type == 1) {
                int chair = availableChairs.top(); 
                availableChairs.pop();
                occupiedChair[friendIndex] = chair;
                
                if (friendIndex == targetFriend) {
                    return chair; 
                }
            } else { // Departure
                availableChairs.push(occupiedChair[friendIndex]); 
            }
        }
        
        return -1;
    }
};