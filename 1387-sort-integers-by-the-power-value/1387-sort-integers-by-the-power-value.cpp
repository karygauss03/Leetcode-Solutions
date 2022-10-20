class Solution {
private:
    vector<int> dp;
    priority_queue<pair<int,int>> q;
    void precompute(){
        // memset(dp, -1, sizeof dp);*
        dp.assign(1005, -1);
        dp[0] = 0;
        dp[1] = 0;
        dp[2] = 1;
        for (int i = 3 ; i <= 1000 ; i++){
            int cnt = 0;
            int cur = i;
            while (i > 1){
                if (i <= 1000 && dp[i] != -1){
                    dp[cur] = cnt + dp[i];
                    break;
                }
                if (i % 2 == 0){
                    i /= 2;
                    cnt++;
                }
                else {
                    i *= 3;
                    ++i;
                    cnt++;
                }
            }
            if (dp[cur] == -1)
                dp[cur] = cnt;
        } 
    }
public:
    int getKth(int lo, int hi, int k) {
        precompute();
        for (int i = lo ; i <= hi ; i++){
            int pow = dp[i];
            q.push(make_pair(pow, i));
            if (q.size() > k) q.pop();
        }
        return q.top().second;
    }
};