class Solution {
public:
    string orderlyQueue(string s, int k) {
        if (k > 1){
            sort(s.begin(), s.end());
            return s;
        }
        string tmp = s;
        for (int i = 0 ; i < s.size() ; i++){
            tmp = tmp.substr(1, tmp.size()) + tmp[0];
            s = min(s, tmp);
        }
        return s;
    }
};