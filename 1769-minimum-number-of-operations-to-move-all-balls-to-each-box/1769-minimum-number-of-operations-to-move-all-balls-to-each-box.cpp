class Solution {
public:
    vector<int> minOperations(string boxes) {
        int n = boxes.size();
        vector<int> ans(n);
        for (int i = 0 ; i < n ; i++){
            for (int j = 0 ; j < n ; j++){
                if (j == i) continue;
                if (boxes[j] == '1'){
                    ans[i] += abs(i - j);
                }
            }
        }
        return ans;
    }
};