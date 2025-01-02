class Solution {
public:
    int maxRectangleArea(vector<vector<int>>& points) {
        int n = points.size();
        set<pair<int, int>> st;
        for (const auto& point : points) {
            st.insert({point[0], point[1]});
        }
        int ans = -1;
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                if (points[i][0] != points[j][0] && points[i][1] != points[j][1]) {
                    if (st.count({points[i][0], points[j][1]}) && st.count({points[j][0], points[i][1]})) {
                        int x1 = min(points[i][0], points[j][0]);
                        int x2 = max(points[i][0], points[j][0]);
                        int y1 = min(points[i][1], points[j][1]);
                        int y2 = max(points[i][1], points[j][1]);
                        bool hasInvalidPoint = false;
                        for (const auto& point : points) {
                            int x = point[0], y = point[1];
                            if ((x > x1 && x < x2 && y >= y1 && y <= y2) ||
                                (y > y1 && y < y2 && x >= x1 && x <= x2)) {
                                if (!(x == x1 && y == y1) &&
                                    !(x == x1 && y == y2) &&
                                    !(x == x2 && y == y1) &&
                                    !(x == x2 && y == y2)) {
                                    hasInvalidPoint = true;
                                    break;
                                }
                            }
                        }
                        if (!hasInvalidPoint) {
                            int area = (x2 - x1) * (y2 - y1);
                            ans = max(ans, area);
                        }
                    }
                }
            }
        }
        return ans;
    }
};
