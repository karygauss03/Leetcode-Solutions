class Solution {
public:
    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
        int n = nums.size(), m = queries.size();
        long long sum = 0, cur;
        vector<int> ans;
        for (int i = 0 ; i < n ; i++){
            sum += nums[i];
        }
        sort(nums.rbegin(), nums.rend());
        for (int i = 0 ; i < m ; i++){
            cur = sum;
            int val = queries[i];
            int j = 0;
            while (val < cur){
                cur -= nums[j];
                j++;
            }
            ans.push_back(n - j);
        }
        return ans;
    }
};