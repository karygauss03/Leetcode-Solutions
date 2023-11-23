class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        set<int> distinct;
        for (auto &n : nums) {
            int before = distinct.size();
            distinct.insert(n);
            if (before == distinct.size()) {
                return true;
            }
        }
        return false;
    }
};