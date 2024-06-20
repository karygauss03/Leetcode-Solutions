class Solution {
private:
    bool isPossible (vector<int>& position, int m, int mid) {
        int cur = position[0];
        --m;
        for (int i = 1; i < position.size(); ++i) {
            if (m == 0) {
                return true;
            }
            if (position[i] - cur >= mid) {
                --m;
                cur = position[i];
            }
        }
        return m == 0;
    }
public:
    int maxDistance(vector<int>& position, int m) {
        sort(position.begin(), position.end());
        int left = 1, mid, right = position[position.size() - 1] / (m - 1), ans = 0;
        while (left <= right) {
            mid = (left + right) / 2;
            if (isPossible(position, m, mid)) {
                ans = mid;
                left = mid + 1;
            }
            else {
                right = mid - 1;
            }
        }
        
        return ans;
    }
};