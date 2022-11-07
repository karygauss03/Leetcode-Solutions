class Solution {
public:
    int maximum69Number (int num) {
        string n = to_string(num);
        string r;
        bool is_change = false;
        for (auto i : n) {
            if (i == '6' && is_change == false) {
                r += '9';
                is_change = true;
            }
            else
                r += i;
        }
        int res = stoi(r);
        return res;
    }
};