class Solution {
public:
    int countPrimeSetBits(int left, int right) {
        int ans = 0;
        set<int> s = {2, 3, 5, 7, 11, 13, 17, 19};
        for (int i = left ; i <= right ; i++){
            int cnt = __builtin_popcount(i);
            if (s.find(cnt) != s.end()){
                ans++;
            }
        }
        return ans;
    }
};