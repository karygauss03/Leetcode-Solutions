class FenwickTree {
public:
    FenwickTree(int n): n_(n), bit_(n, 0) {}

    int sum(int r) {
        int ret = 0;
        for (; r >= 0; r = (r & (r + 1)) - 1)
            ret += bit_[r];
        return ret;
    }

    void add(int idx, int delta) {
        for (; idx < n_; idx = idx | (idx + 1))
            bit_[idx] += delta;
    }

private:
    vector<int> bit_;  // binary indexed tree
    int n_;
};

class Solution {
public:
    vector<int> countRectangles(vector<vector<int>>& rectangles, vector<vector<int>>& points) {
        const int n = rectangles.size(), m = points.size();
        std::vector<int> idx(m, 0), res(m, 0);
        std::iota(idx.begin(), idx.end(), 0);

        std::sort(rectangles.begin(), rectangles.end(), [](const auto &r1, const auto &r2){
            return r1[0] > r2[0];
        });
        std::sort(idx.begin(), idx.end(), [&](const auto i, const auto j){
            return points[i][0] > points[j][0];
        });
        
        FenwickTree bit(100 + 1);
        for(int i = 0, rect_i = 0; i < m; ++i){
            while(rect_i < n && rectangles[rect_i][0] >= points[idx[i]][0]){
                bit.add(rectangles[rect_i++][1], 1);
            }
            res[idx[i]] = rect_i - bit.sum(points[idx[i]][1] - 1); // all added rectangles - shorter rectangles
        }
        return res;
    }
};