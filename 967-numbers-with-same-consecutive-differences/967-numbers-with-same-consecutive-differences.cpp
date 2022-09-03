class Solution {
public:
    void solve (int n, int prev, int k, string s, vector<int> &ans) {
        if (n == 0) {
            ans.push_back (stoi(s));
            return;
        }
        for (int i = 0; i < 10; i++) {
            bool flag = 0;
            if (prev == -1 || abs(i-prev) == k) {
                if (prev == -1 && i == 0)
                    continue;
                flag = 1;
                s += i + '0';
                solve (n-1,i,k,s,ans);
            }
            if (flag) {
                s.pop_back();
            }
            flag = 0;
        }
    }
    vector<int> numsSameConsecDiff(int n, int k) {
        vector<int> ans;
        string s;
        solve (n, -1, k, s, ans);
        return ans;
    }
};