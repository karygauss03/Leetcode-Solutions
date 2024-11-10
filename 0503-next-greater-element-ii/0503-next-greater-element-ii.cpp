class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n, -1);
        stack<int> st;
        for (int j = 0; j < 2; ++j) {
            for (int i = 0; i < n; ++i) {
                while(!st.empty() && nums[i] > nums[st.top()]) {
                    ans[st.top()] = nums[i];
                    st.pop();
                }

                st.push(i);
            }
        }
        return ans;
    }
};