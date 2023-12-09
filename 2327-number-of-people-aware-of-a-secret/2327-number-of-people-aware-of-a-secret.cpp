class Solution {
public:
    int MOD = (int)1e9 + 7;
    int peopleAwareOfSecret(int n, int delay, int forget) {
        queue<pair<int, long long>> forgetQ, delayQ;
        int ans = 1;
        long long cnt = 0;
        delayQ.push({delay + 1, 1});
        forgetQ.push({forget + 1, 1});
        int i = 1;
        
        while (++i <= n) {
            while (!forgetQ.empty() && forgetQ.front().first == i) {
                cnt = ((cnt%MOD) - (forgetQ.front().second%MOD) + MOD) % MOD;
                ans = ((ans%MOD) - (forgetQ.front().second%MOD) + MOD) % MOD;
                forgetQ.pop();
            }
            
            while (!delayQ.empty() && delayQ.front().first == i) {
                cnt += delayQ.front().second;
                cnt %= MOD;
                delayQ.pop();
            }
            
            ans += cnt;
            ans %= MOD;
            if (cnt != 0) {
                delayQ.push({i + delay, cnt});
                forgetQ.push({i + forget, cnt});
            }
        }
        ans %= MOD;
        return ans;
    }
};