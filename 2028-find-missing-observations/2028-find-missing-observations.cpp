class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        int m = rolls.size();
        int sum_m = 0;
        for (auto& roll: rolls) {
            sum_m += roll;
        }
        int sum_n = (n + m) * mean - sum_m;
        if (sum_n < n || sum_n > 6 * n) {
            return {};
        }
        
        vector<int> ans(n, sum_n / n);
        for (int i = 0; i < sum_n % n; ++i) {
            ++ans[i];
        }
        return ans;
    }
};