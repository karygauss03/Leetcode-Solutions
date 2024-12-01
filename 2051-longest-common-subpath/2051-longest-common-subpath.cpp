class Solution {
private:
    int BASE = 100001;
    int MOD = 1e9 + 7;

    bool check(int mid, vector<vector<int>>& paths, int n) {
        unordered_map<int, vector<int>> prevPathsHashes;
        for (int i = 0; i < paths.size() && (i == 0 || !prevPathsHashes.empty()); ++i) {
            long long hashPath = 0, pow = 1;
            unordered_map<int, vector<int>> curPathHashes;
            for (int j = 0; j < paths[i].size(); ++j) {
                hashPath = (hashPath * BASE + paths[i][j]) % MOD;
                if (j >= mid) {
                    hashPath = (MOD + hashPath - pow * paths[i][j - mid] % MOD) % MOD;
                } else {
                    pow = pow * BASE % MOD;
                }
                if (j >= mid - 1) {
                    if (i == 0) {
                        curPathHashes[hashPath].push_back(j + 1 - mid);
                    } else {
                        if (prevPathsHashes.count(hashPath)) {
                            for (auto& idx : prevPathsHashes[hashPath]) {
                                if (equal(begin(paths[0]) + idx,
                                          begin(paths[0]) + idx + mid,
                                          begin(paths[i]) + j + 1 - mid)) {
                                    curPathHashes[hashPath].push_back(idx);
                                    break;
                                }
                            }
                        }
                    }
                }
            }
            swap(prevPathsHashes, curPathHashes);
        }
        return !prevPathsHashes.empty();
    }

public:
    int longestCommonSubpath(int n, vector<vector<int>>& paths) {
        int l = 1, r = INT_MAX;
        for (const auto& path : paths) {
            r = min(r, (int)path.size());
        }
        int result = 0;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (check(mid, paths, n)) {
                result = mid;
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        return result;
    }
};
