class Solution {
public:
    int maxWidthOfVerticalArea(vector<vector<int>>& points) {
        set<int> s;
        int res = 0;
        for (auto i : points) {
            s.insert(i[0]);
        }
        for (auto it = next(begin(s)); it != end(s); ++it) {
            res = max(res, *it - *prev(it));
        }
        return res;
    }
};