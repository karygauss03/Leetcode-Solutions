class Solution {
public:
    int minPartitions(string s) {
        int x = 0;
        for(auto &it:s){
            x = max(x,it-'0');
        }
        return x;
    }
};