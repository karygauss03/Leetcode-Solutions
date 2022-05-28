class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int prod = 1;
        bool zero = false;
        int n = nums.size();
        set<int> z;
        for (int i = 0 ; i < n ; i++){
            if (nums[i] == 0) {
                zero = true;
                z.insert(i);
            }
            else prod *= nums[i];
        }
        
        vector<int> ans;
        for (int i = 0 ; i < n ; i++){
            if (nums[i] != 0 && zero){
                ans.push_back(0);
            }
            else if (nums[i] != 0 && !zero){
                ans.push_back(prod/nums[i]);
            }
            else {
                if (z.size() == 1){
                    ans.push_back(prod);
                }
                else {
                    ans.push_back(0);
                }
            }
        }
        return ans;
    }
};