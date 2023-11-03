class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        int m = target.size();
        vector<string> ans;
        int i = 1, j = 0;
        while(i <= n){
            if(j == m) break;
            if (i == target[j]){
                ++i;
                ++j;
                ans.push_back("Push");
            }
            else {
                ans.push_back("Push");
                ans.push_back("Pop");
                ++i;
            }
        }
        return ans;
    }
};