class Solution {
public:
    int buyChoco(vector<int>& p, int money) {
        nth_element(begin(p), begin(p) + 1, end(p));
        return money < p[0] + p[1] ? money : money - p[0] - p[1];
    }
};