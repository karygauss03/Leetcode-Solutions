class Solution {
public:
    int minimumLength(string str) {
        unordered_map<char, int> freqMap;
        for (char ch : str) {
            freqMap[ch]++;
        }

        int toDelete = 0;
        for (auto& entry : freqMap) {
            int count = entry.second;
            if (count % 2 == 1) {
                toDelete += count - 1;
            } else {
                toDelete += count - 2;
            }
        }

        return str.length() - toDelete;
    }
};
