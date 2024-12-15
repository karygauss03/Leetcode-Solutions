class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& cls, int e) {
        auto g = [](int p, int t) {
            return (double)(p + 1) / (t + 1) - (double)p / t;
        };

        priority_queue<pair<double, pair<int, int>>> h;
        for (auto& c : cls) h.push({g(c[0], c[1]), {c[0], c[1]}});

        while (e--) {
            auto [cg, ci] = h.top(); h.pop();
            int p = ci.first, t = ci.second;
            h.push({g(p + 1, t + 1), {p + 1, t + 1}});
        }

        double res = 0;
        while (!h.empty()) {
            auto [_, ci] = h.top(); h.pop();
            res += (double)ci.first / ci.second;
        }

        return res / cls.size();
    }
};
