class Solution {
public:
    int maxCoins(vector<int>& piles) {
        sort(piles.begin(), piles.end());
        int cur = piles.size() - 2;
        int cnt = piles.size() / 3;
        int ans = 0;
        while (cnt){
            ans += piles[cur];
            cur -= 2;
            cnt--;
        }
        return ans;
    }
};