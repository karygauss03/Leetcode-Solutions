class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        map<int, int> ma;
        set<int> ss;
        for (auto &a : arr){
            ma[a]++;
        }
        for (auto &m : ma){
            if (ss.find(m.second) != ss.end()){
                return false;
            }
            ss.insert(m.second);
        }
        return true;
    }
};