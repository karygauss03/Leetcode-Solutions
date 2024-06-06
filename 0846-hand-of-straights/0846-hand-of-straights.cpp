class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int n = hand.size();
        if (n % groupSize != 0) {
            return false;
        }
        if (groupSize == 1) {
            return true;
        }
        int k = n / groupSize;
        int done = 0;
        sort(hand.begin(), hand.end());
        queue<pair<int, int>> q;
        pair<int, int> fr;
        for (int i = 0; i < n; i++) {
            if (q.empty() || q.front().first + 1 != hand[i]) {
                q.push({hand[i], 1});
                continue;
            }
            fr = q.front();
            q.pop();
            if (fr.second != groupSize - 1) {
                q.push({hand[i], fr.second + 1});
            } else {
                done++;
            }
        }
        return (done == k);
    }
};