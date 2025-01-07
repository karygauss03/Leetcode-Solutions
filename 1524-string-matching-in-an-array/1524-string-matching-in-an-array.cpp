class Solution {
private:
    bool hasPattern(const string& txt, const string& pat) {
        int n1 = txt.size(), n2 = pat.size();
        vector<int> lP(n2, 0);
        genLP(pat, lP);
        int x = 0, y = 0;
        while (x < n1) {
            if (txt[x] == pat[y]) {
                ++x;
                ++y;
                if (y == n2) return true;
            } else if (y > 0) {
                y = lP[y - 1];
            } else {
                ++x;
            }
        }
        return false;
    }

    void genLP(const string& p, vector<int>& lp) {
        int l = 0;
        lp[0] = 0;
        int j = 1;
        while (j < p.size()) {
            if (p[j] == p[l]) {
                ++l;
                lp[j] = l;
                ++j;
            } else if (l > 0) {
                l = lp[l - 1];
            } else {
                lp[j] = 0;
                ++j;
            }
        }
    }

public:
    vector<string> stringMatching(vector<string>& strs) {
        vector<string> res;
        sort(strs.begin(), strs.end(), [](const string& a, const string& b) {
            return a.size() < b.size();
        });
        for (int i = 0; i < strs.size(); ++i) {
            for (int k = i + 1; k < strs.size(); ++k) {
                if (hasPattern(strs[k], strs[i])) {
                    res.push_back(strs[i]);
                    break;
                }
            }
        }
        return res;
    }
};
