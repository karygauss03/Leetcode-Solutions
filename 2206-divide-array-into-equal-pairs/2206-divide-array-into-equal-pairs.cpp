class Solution {
public:
    bool divideArray(vector<int>& nums) {
        map<int, int> ma;
        for (auto &num : nums){
            ma[num]++;
        }
        for (auto &m : ma){
            if (m.second & 1){
                return false;
            }
        }
        return true;
    }
};