class Solution {
public:
    int minMovesToSeat(vector<int>& seats, vector<int>& students) {
        sort(seats.begin(), seats.end());
        sort(students.begin(), students.end());
        int ans = 0;
        for (int i = 0, j = 0; i < seats.size(); ++i, ++j) {
            ans += abs(seats[i] - students[j]);
        }
        return ans;
    }
};