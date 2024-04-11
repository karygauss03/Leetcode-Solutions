class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int ans = 0, i = 0;
        set<int> goodTypes;
        unordered_map<int, int> freq;
        for (int j = 0; j < fruits.size(); ++j) {
            if (goodTypes.size() < 2) {
                goodTypes.insert(fruits[j]);
                freq[fruits[j]]++;
            }
            else {
                if (goodTypes.count(fruits[j]) == 1) {
                    freq[fruits[j]]++;
                }
                else {
                    while(freq[fruits[i]] != 0) {
                        freq[fruits[i]]--;
                        if (freq[fruits[i]] == 0) {
                            goodTypes.erase(fruits[i]);
                            ++i;
                            break;
                        }
                        ++i;
                    }
                    freq[fruits[j]]++;
                    goodTypes.insert(fruits[j]);
                }
            }
            ans = max(ans, j + 1 - i);
        }
        return ans;
    }
};
