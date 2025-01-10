class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        vector<int> mxFreq(26, 0);
        for (auto &word : words2) {
            vector<int> tmpFreq(26, 0);
            for (auto &c : word) {
                tmpFreq[c - 'a']++;
            }
            for (int i = 0; i < 26; ++i) {
                mxFreq[i] = max(mxFreq[i], tmpFreq[i]);
            }
        }

        vector<string> ans;
        for (auto &word : words1) {
            vector<int> tmpFreq(26, 0);
            for (auto &c : word) {
                tmpFreq[c - 'a']++;
            }
            bool isUniversal = true;
            for (int i = 0; i < 26; ++i) {
                // cout << (char)('a' + i) << ' ' << mxFreq[i] << '#' << tmpFreq[i] << endl;
                if (tmpFreq[i] < mxFreq[i]) {
                    isUniversal = false;
                    break;
                }
            }
            if (isUniversal) {
                ans.push_back(word);
            }
            cout << "------\n";
        }

        return ans;
    }
};