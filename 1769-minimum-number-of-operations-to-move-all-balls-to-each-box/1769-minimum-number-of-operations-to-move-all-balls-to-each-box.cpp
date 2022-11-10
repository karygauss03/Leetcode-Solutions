class Solution {
public:
    vector<int> minOperations(string boxes) {
        int n = boxes.size();
        vector<int> ans(n);
        int count_left = 0, count_right = 0;
        int sum_left = 0, sum_right = 0;
        for (int i = 0 ; i < n ; i++){
            if (boxes[i] == '1'){
                count_right++;
                sum_right += i;
            }
        }
        for (int i = 0 ; i < n  ; i ++){
            if (boxes[i] == '1'){
                count_right--;
                sum_right -= i;
            }
            ans[i] = abs(sum_right - (count_right*i)) + abs(sum_left - (count_left * i));
            if (boxes[i] == '1'){
                count_left++;
                sum_left += i;
            }
        }
        return ans;
    }
};