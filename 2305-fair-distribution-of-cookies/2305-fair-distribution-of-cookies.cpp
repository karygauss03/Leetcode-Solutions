class Solution {
public:
    int ans = INT_MAX;
    int fair;
    void solve(int idx, int len, int k, int* res, vector<int>& cookies){
        if(idx >= len){
            int tmp = -INT_MAX;
            for(int i=0; i<k; i++){
                tmp = max(tmp, res[i]);
            }
            ans = min(ans, tmp);
            return;
        }
        for(int i=0; i<k; i++){
            if(i>0 && res[i]==res[i-1]) continue;
            if (res[i] >= fair) continue;
            res[i] += cookies[idx];
            solve(idx+1, len, k, res, cookies);
            res[i] -= cookies[idx];
        }
    }
    int distributeCookies(vector<int>& cookies, int k) {
        int len = cookies.size();
        int res[k]; memset(res, 0, sizeof(int)*k);
        fair = accumulate(cookies.begin(),cookies.end(),0) / k;
        sort(cookies.begin(), cookies.end(), greater<int>());
        solve(0, len, k, res, cookies);
        return ans;
    }
};