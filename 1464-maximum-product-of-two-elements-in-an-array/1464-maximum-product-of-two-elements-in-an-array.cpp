class Solution {
public:
    int maxProduct(vector<int>& nums) {
        auto m1 = 0, m2 = 0;
        for (auto n: nums) {
            if (n > m1)
                m2 = exchange(m1, n);
            else
                m2 = max(m2, n);
        }
        return (m1 - 1) * (m2 - 1);
    }
};