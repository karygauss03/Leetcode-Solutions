class Solution {
public:
    long long wonderfulSubstrings(string word) {
        unordered_map<int, int> count;
        int mask = 0;
        count[0] = 1;
        long long result = 0;
        for(char c : word) {
            mask ^= 1 << (c - 'a');
            result += count[mask];
            for(int i = 0; i < 10; i++) {
                result += count[mask ^ (1 << i)];
            }
            count[mask]++;
        }
        return result;
    }
};