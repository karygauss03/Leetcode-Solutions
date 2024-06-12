class Solution {
public:
    void sortColors(vector<int>& nums) {
        if (nums.size() == 1) {
            return;
        }
        int count[3] = {0, 0, 0};
        for (int i = 0; i  < nums.size(); ++i) {
            count[nums[i]]++;
        }
        
        int i = 0, j = 0;
        while (j < 3 && i < nums.size()) {
            if (count[j] == 0) {
                ++j;
                continue;
            }
            nums[i++] = j;
            --count[j];
        }
    }
};