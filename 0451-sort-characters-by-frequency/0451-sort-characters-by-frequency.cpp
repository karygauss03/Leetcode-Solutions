class Solution {
public:
    string frequencySort(string s) {
        map<char, int> ma;
        for (auto &c : s) ma[c]++;
        
        vector<pair<int, char>> v;
        for (auto &m : ma){
            v.push_back(make_pair(m.second, m.first));
        }
        string ans = "";
        sort(v.rbegin(), v.rend());
        for (auto &p : v){
            for (int i = 0 ; i < p.first ; i++){
                ans += p.second;
            }
        }
        return ans;
    }
};