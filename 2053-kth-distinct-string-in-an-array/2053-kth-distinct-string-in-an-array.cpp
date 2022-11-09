class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        unordered_map<string, int> ma;
        for (auto &s : arr){
            ma[s]++;
        }
        for (auto &s : arr){
            if (ma[s] == 1){
                k--;
                if (k == 0){
                    return s;
                }
            }
        }
        return "";
    }
};