class FenwickTree {
    vector<int> val;
    int SIZE;
    
public:
    FenwickTree(int n) {
        int s = 1;
        while (s < n) {
            s <<= 1;
        }
        val = vector<int>(s + 1, 0);
        SIZE = s + 1;
    }

    int lower_bound(int value) {
        int i = 0;
        int j = SIZE - 1;
        
        value -= val[0];
        for (; j > 0; j >>= 1) {
            if (i + j < SIZE && val[i + j] < value) {
                value -= val[i + j];
                i += j;
            }
        }
        
        return i;
    }

    void update(int i, int delta) {
        if (i == 0) {
            val[0] += delta;
            return;
        }

        for (; i < SIZE; i = get_child(i)) {
            val[i] += delta;
        }
    }
    
private:
    inline int get_child(int i) {
        return i + (i & -i);
    }
};

class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        sort(people.begin(), people.end(), [](auto &a, auto &b) {
            if (a[0] != b[0]) {
                return a[0] < b[0];
            }
            return b[1] < a[1];
        });

        FenwickTree ft(people.size() + 1);
        for (int i = 1; i < people.size() + 1; i++) {
            ft.update(i, 1);
        }
        
        vector<std::vector<int>> ans(people.size());
        for (auto &p : people) {
            int blanks_needed = p[1] + 1;
            int idx = ft.lower_bound(blanks_needed);
            ft.update(idx + 1, -1);
            ans[idx] = p;
        }
        return ans;
    }
};
