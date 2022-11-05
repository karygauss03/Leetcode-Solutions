#define show(x) cout << #x << " = " << x << endl
class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        if (nums.size() == 1) return 1;
        pair<int, int> mx, mn;
        mx = {nums[0], 0};
        mn = {nums[0], 0};
        for (int i = 1 ; i < nums.size() ; i++){
            if (mx.first < nums[i]){
                mx.first = nums[i];
                mx.second = i;
            }
            if (mn.first > nums[i]){
                mn.first = nums[i];
                mn.second = i;
            }
        }
        //case 1: we delete from the front
        int front = max(mx.second, mn.second) + 1;
        //case 2: we delete from the back
        int back = nums.size() - min(mx.second, mn.second);
        //case 3: we delete from back and front
        int first_element = min(mn.second, mx.second);
        int second_element = max(mn.second, mx.second);
        int front_back = min(first_element + nums.size() - second_element + 1, second_element + nums.size() - first_element + 1);

        return min(front, min(back, front_back));
    }
};