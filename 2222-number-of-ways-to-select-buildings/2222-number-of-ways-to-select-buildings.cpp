class Solution {
public:
    long long numberOfWays(string s) {
        int n = s.size();
        long long ans = 0;
        int pref[n + 5];
        pref[0] = (s[0] - '0');
        
        for (int i = 1 ; i < n ; i++){
            pref[i] = pref[i - 1] + (s[i] - '0');
        }
        for (int i = 1 ; i < n - 1; i++){
            long long before = pref[i - 1];
            long long after = pref[n - 1] - pref[i];
            if (s[i] == '1'){
                before = abs(i - before);
                after = abs(n - i - after - 1);
            }
            ans += before * after;
        }
        return ans;
    }
};