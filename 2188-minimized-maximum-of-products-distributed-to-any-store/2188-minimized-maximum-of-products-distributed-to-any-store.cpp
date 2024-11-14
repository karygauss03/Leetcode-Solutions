class Solution {
private:
    bool distribute(int n, vector<int> quantities, int mid) {
        int cnt = 0;
        
        for (int i = 0; i < quantities.size(); ++i) {
            cnt += (quantities[i] + mid - 1) / mid;
        }
        
        return cnt <= n;
    }
public:
    int minimizedMaximum(int n, vector<int>& quantities) {
        int left = 1, right = *max_element(quantities.begin(), quantities.end());
        int mid;
        int ans = right;
        while (left <= right) {
            mid = (left + right) / 2;
            if (distribute(n, quantities, mid)) {
                ans = min(ans, mid);
                right = mid - 1;
            }
            else {
                left = mid + 1;
            }
        }
        return ans;
    }
};