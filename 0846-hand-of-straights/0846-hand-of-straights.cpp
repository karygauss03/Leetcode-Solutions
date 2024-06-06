class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        if (hand.size() % groupSize != 0) {
            return false;
        }
        map<int, int> freq;
        for (auto &h : hand) {
            freq[h]++;
        }
        while (!freq.empty()) {
            int min_val = freq.begin()->first;
            
            for (int i = 0; i < groupSize; ++i) {
                if (freq.find(min_val + i) == freq.end()) {
                    return false;
                }
                freq[min_val + i]--;
                if (freq[min_val + i]<1) {
                    freq.erase(min_val + i);
                }
            }
        }
        
        return true;
    }
};