class Solution {
public:
    int minFlips(string target) {
        int n = target.size();
        int ans = 0;
        string zeros = "", ones = "";
        for (int i = 0 ; i < n ; i++) {
            ones += '1';
            zeros += '0';
        }
        string cur = zeros;
        for (int i = 0 ; i < n ; i++){
            if (cur[i] == target[i]) continue;
            ans++;
            if (ans % 2) cur = ones;
            else cur = zeros;
        }
        return ans;
    }
};