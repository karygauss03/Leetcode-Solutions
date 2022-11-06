class Solution {
public:
    vector<string> readBinaryWatch(int turnedOn) {
        vector<string>ans;
        string h;
        for(int i = 0; i < 12; i++){
            for(int j = 0; j < 60; j++){
                h = "";
                if(__builtin_popcount(i) + __builtin_popcount(j) == turnedOn){
                    string hours = to_string(i);
                    string mins = (j > 9) ? to_string(j) : "0" + to_string(j);
                    h = hours + ":" + mins;
                    ans.push_back(h);
                }
            }
        }
        return ans;
    }
};