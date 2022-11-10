class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        vector<pair<int, int>> less, greater;
        vector<int> ans;
        int equal = 0;
        for (int i = 0 ; i < nums.size() ; i++){
            if (nums[i] == pivot) equal++;
            if (nums[i] < pivot){
                less.push_back(make_pair(i, nums[i]));
            }
            if (nums[i] > pivot){
                greater.push_back(make_pair(i, nums[i]));
            }
        }
        sort(less.begin(), less.end());
        sort(greater.begin(), greater.end());
        for (auto &x : less){
            ans.push_back(x.second);
        }
        while (equal){
            ans.push_back(pivot);
            equal--;
        }
        for (auto &x : greater){
            ans.push_back(x.second);
        }
        return ans;
    }
};