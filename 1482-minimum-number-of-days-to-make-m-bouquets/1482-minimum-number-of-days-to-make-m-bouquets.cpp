class Solution {
private:
    int possibleNumberOfBouquets(vector<int>& bloomDay, int k, int mid) {
        int res = 0, cnt = 0;
        for (int i = 0; i < bloomDay.size(); ++i) {
            if (bloomDay[i] <= mid) {
                ++cnt;
            }
            else {
                cnt = 0;
            }
            if (cnt == k) {
                ++res;
                cnt = 0;
            }
        }
        return res;
    }
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        int left = *min_element(bloomDay.begin(), bloomDay.end()), right = *max_element(bloomDay.begin(), bloomDay.end());
        int ans = -1, mid, cur;
        while (left <= right) {
            mid = (right + left) / 2;
            cur = possibleNumberOfBouquets(bloomDay, k, mid);
            if (cur >= m) {
                right = mid - 1;
                ans = mid;
            }
            else {
                left = mid + 1;
            }
        }
        return ans;
    }
};