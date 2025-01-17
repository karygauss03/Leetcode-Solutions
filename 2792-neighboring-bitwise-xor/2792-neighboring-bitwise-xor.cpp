class Solution {
public:
    bool doesValidArrayExist(vector<int>& d) {
        int n = d.size();
        vector<int> orig(n);
        for (int i = 0; i < n; ++i) {
            if (i == n - 1) {
                if (d[i] == 0 && orig[n - 1] != orig[0]) return false;
                if (d[i] == 1 && orig[n - 1] == orig[0]) return false; 
            }
            else {
                if (d[i] == 0) {
                    if (i == 0) {
                        orig[i] = 1, orig[i + 1] = 1;
                    }
                    else {
                        orig[i + 1] = orig[i];
                    }
                }
                else {
                    if (i == 0) {
                        orig[i] = 1, orig[i + 1] = 0;
                    }
                    else {
                        orig[i + 1] = 1 - orig[i];
                    }
                }
            }
        }
        return true;
    }
};