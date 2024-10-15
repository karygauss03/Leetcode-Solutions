class Solution {
public:
    long long minimumSteps(string s) {
        long long ans = 0;
        int n = s.size();
        int suffix[n];
        suffix[n - 1] = '1' - s[n - 1];
        for (int i = n - 2; i >= 0; --i) {
            suffix[i] = suffix[i + 1] + ('1' - s[i]);
        }
        
        for (int i = 0; i < n; ++i) {
            if (s[i] == '1') {
                ans += (long long)suffix[i];
            }
        }
        
        return ans;
    }
};