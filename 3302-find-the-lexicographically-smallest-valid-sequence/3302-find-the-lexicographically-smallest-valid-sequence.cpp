class Solution {
private:
    int n, m;
    vector<int> ans;
public:
    vector<int> validSequence(string word1, string word2) {
        n = word1.size(), m = word2.size();
        int suffix[m + 1];
        memset(suffix, -1, sizeof suffix);
        int j = n - 1;
        for (int i = m - 1; i >= 0; --i) {
            while (j >= 0 && word1[j] != word2[i]) {
                --j;
            }
            suffix[i] = j;
            if (j < 0) {
                break;
            }
            --j;
        }
        suffix[m] = n;
        bool flag = false;
        j = 0;
        for (int i = 0; i < n; ++i) {
            if (j >= m) {
                break;
            }
            if (word1[i] == word2[j]) {
                ans.push_back(i);
                ++j;
                continue;
            }

            if (!flag && suffix[j + 1] >= i + 1) {
                ans.push_back(i);
                ++j;
                flag = true;
            }
        }
        return ans.size() == m ? ans : vector<int>();
    }
};