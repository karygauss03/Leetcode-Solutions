class Solution {
public:
    vector<int> minOperations(string boxes) {
        int n = boxes.size();
        vector<int> prefix(n, 0);
        int cnt = boxes[0] == '1';
        for (int i = 1; i < n; ++i) {
            prefix[i] = prefix[i - 1] + cnt;
            cnt += (boxes[i] == '1');
        }
        cnt = boxes[n - 1] == '1';
        vector<int> suffix(n, 0);
        for (int i = n - 2; i >= 0; --i) {
            suffix[i] = suffix[i + 1] + cnt;
            cnt += (boxes[i] == '1');
        }
        vector<int> ans;
        for (int i = 0; i < n; ++i) ans.push_back(prefix[i] + suffix[i]);
        return ans;
    }
};