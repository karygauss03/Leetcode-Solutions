class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        map<int, int> ma;
        vector<int> ans;
        for(auto& num : nums) {
            ma[num]++;
            if (ma[num] == 2) {
                ans.push_back(num);
            }
        }
        return ans;
    }
};