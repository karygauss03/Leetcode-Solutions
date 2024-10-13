class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> minHeap;
        int s = 0, e = 1e7, mx = INT_MIN;
        for (int i = 0; i < nums.size(); ++i) {
            minHeap.push({nums[i][0], i, 0}); // {val, list_index, element_index}
            mx = max(mx, nums[i][0]);
        }
        while(minHeap.size() == nums.size()) {
            auto top = minHeap.top();
            minHeap.pop();
            int element = top[0], list_index = top[1], element_index = top[2];
            if (mx - element < e - s) {
                s = element, e = mx;
            }
            if (element_index + 1  < nums[list_index].size()) {
                minHeap.push({nums[list_index][element_index + 1], list_index, element_index + 1});
                mx = max(mx, nums[list_index][element_index + 1]);   
            }
        }
        
        return {s, e};
    }
};