class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int mod = 1e9 + 7;
        int n = arr.size();
        stack<int> st;
        int dp[n];
        int ans = 0;
        for (int i = 0 ; i < n ; i++){
            while (!st.empty() && arr[st.top()] >= arr[i]){
                st.pop();
            }
            
            if (st.size()){
                dp[i] = (dp[st.top()] + (i - st.top())*arr[i]) % mod;
            }
            else {
                dp[i] = ((i + 1) * arr[i]) % mod;
            }
            ans += dp[i];
            ans %= mod;
            st.push(i);
        }
        return ans;
    }
};