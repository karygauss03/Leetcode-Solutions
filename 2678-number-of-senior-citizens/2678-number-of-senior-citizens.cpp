class Solution {
public:
    int countSeniors(vector<string>& details) {
        int cnt = 0;
        for(const auto& person : details){
            int age = stoi(person.substr(11, 2));
            if(age > 60){
                cnt++;
            }
        }
        return cnt;
    }
};