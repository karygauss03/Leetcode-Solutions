class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& a, int k) {
        int n = a.size();
        int ans = 0;
        int i = 0, j = 0;
        int prod = 1;
        while (i < n && j < n){
            prod *= a[j];
            if (prod < k){
                ans += j - i + 1;
            }
            else {
                while (i < n && prod >= k && i <= j){
                    prod /= a[i];
                    i++;
                }
                ans += (j - i + 1);
            }
            j++;
        }
        
        return ans;
    }
};