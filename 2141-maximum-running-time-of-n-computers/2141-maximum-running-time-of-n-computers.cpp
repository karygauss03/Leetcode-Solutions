typedef long long ll;
class Solution {
public:
    bool check(vector<int>& batteries, int n, ll mid) {
        ll tot = n * mid;
        ll currentSum = 0;
        for (auto& bat : batteries) {
            if (bat > mid) {
                currentSum += mid;
            }
            else {
                currentSum += bat;
            }
            if (currentSum >= tot) {
                return true;
            }
        }
        return (currentSum >= tot);
    }
    long long maxRunTime(int n, vector<int>& batteries) {
        ll left = *min_element(batteries.begin(), batteries.end());
        ll sum = accumulate(batteries.begin(), batteries.end(), 0LL);
        ll right = (sum / n) + 1;
        ll ans = 0;
        while (left < right) {
            ll mid = left + (right - left) / 2;
            if (check(batteries, n, mid)) {
                ans = mid;
                left = mid + 1;
            }
            else {
                right = mid;
            }
        }
        return ans;
    }
    
};