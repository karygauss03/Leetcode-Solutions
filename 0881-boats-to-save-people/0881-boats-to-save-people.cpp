class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        int n = people.size();
        
        sort(people.begin(), people.end());
        int ans = 0;
        int lo = 0, hi = n - 1;
        while(lo < hi){
            if (people[lo] + people[hi] <= limit){
                ans++;
                lo++;
                hi--;
            }
            else {
                ans++;
                hi--;
            }
        }
        if (lo == hi){
            ans++;
        }
        return ans;
    }
};