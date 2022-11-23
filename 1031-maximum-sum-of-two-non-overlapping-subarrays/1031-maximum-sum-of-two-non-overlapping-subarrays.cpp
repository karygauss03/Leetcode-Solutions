class Solution {
public:
    int n;
    //dp_left[i] => maximum subarray sum of size L from 0 -> index i
    //dp_right[i] => maximum subarray sum of size M from last index -> index i
    
    int solve(vector<int>& A, int L, int M){
        int sum = 0;
        vector<int> dp_left(n, 0), dp_right(n, 0);
        for(int i = 0 ; i < n ; i++){
            if (i < L){
                sum += A[i];
                dp_left[i] = sum;
            }
            else {
                sum += (A[i] - A[i - L]);
                dp_left[i] = max(dp_left[i - 1], sum);
            }
        }
        sum = 0;
        for (int i = n - 1 ; i >= 0 ; i--){
            if (i + M > n - 1){
                sum += A[i];
                dp_right[i] = sum;
            }
            else {
                sum += (A[i] - A[i + M]);
                dp_right[i] = max(dp_right[i + 1], sum);
            }
        }
        int ans = 0;
        for (int i = L - 1 ; i < n - M; i++){
            ans = max(ans, dp_left[i] + dp_right[i + 1]);
        }
        return ans;
    }
    int maxSumTwoNoOverlap(vector<int>& A, int L, int M) {
        n = A.size();
        return max(solve(A, L, M), solve(A, M, L));
    }
};