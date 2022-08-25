class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        map<char, int> occ;
        for (auto &c : magazine){
            occ[c]++;
        }
        for (auto &c : ransomNote){
            if (occ[c] == 0){
                return false;
            }
            occ[c]--;
        }
        return true;
    }
};