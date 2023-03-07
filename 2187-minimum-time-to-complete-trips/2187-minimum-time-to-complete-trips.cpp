class Solution {
public:
    long long minimumTime(vector<int>& time, int totalTrips) {
        long long left = 1;
        long long right = 0;
        for (int t : time) {
            right = max(right, (long long)t);
        }
        right = right * totalTrips;
        long long ans = right;
        while (left <= right) {
            long long mid = (left + right) / 2;
            if (check(mid, totalTrips, time)) {
                ans = mid;
                right = mid-1;
            } else {
                left = mid + 1;
            }
        }
        return ans;
    }
    
    bool check(long long givenTime, int totalTrips, vector<int>& time) {
        long long actualTrips = 0;
        for (auto& t : time) 
            actualTrips += givenTime / t;
        if(actualTrips >= totalTrips)
            return true;
        return false;
    }
};