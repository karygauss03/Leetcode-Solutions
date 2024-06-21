class Solution {
private:
    map<int, long long> freq;
    vector<int> unique;
    vector<long long> dp;
    vector<int> next;
public:
    long long solve(int pos, vector<long long>& dp) {
        if (pos >= unique.size()) {
            return 0;
        }
        if (dp[pos] != -1) {
            return dp[pos];
        }
        // Do not take it
        dp[pos] = solve(pos + 1, dp);
        // take it => unique[pos] * freq[unique[pos]] -> go to the next possible element (lowerbound)
        long long tmp = (unique[pos] * 1ll) * (freq[unique[pos]] * 1LL) + solve(next[pos], dp);
        if (tmp > dp[pos]) {
            return dp[pos] = tmp;
        }
        return dp[pos];
    }
    
    
    long long maximumTotalDamage(vector<int>& power) {
        for (auto &p : power) {
            freq[p]++;
            if (freq[p] == 1) {
                unique.push_back(p);
            }
        }
        sort(unique.begin(), unique.end());
        next.resize(unique.size());
        for (int i = 0; i < unique.size(); ++i) {
            next[i] = lower_bound(unique.begin(), unique.end(), unique[i] + 3) - unique.begin();
        }
        vector<long long> dp(unique.size() + 5, -1);
        return solve(0, dp);
    }
};