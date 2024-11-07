class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        long long ans = 0;
        int n = nums.size();
        stack<int> st;
        for (int i = 0; i <= n; ++i) {
            while (!st.empty() && (i == n || nums[i] <= nums[st.top()])) {
                int mid = st.top();
                st.pop();
                int left = st.empty() ? -1 : st.top();
                ans -= (long long)nums[mid] * (i - mid) * (mid - left);
            }
            st.push(i);
        }
        
        st.pop();
        for (int i = 0; i <= n; ++i) {
            while (!st.empty() && (i == n || nums[i] >= nums[st.top()])) {
                int mid = st.top();
                st.pop();
                int left = st.empty() ? -1 : st.top();
                ans += (long long)nums[mid] * (i - mid) * (mid - left);
            }
            st.push(i);
        }
        
        return ans;
    }
};