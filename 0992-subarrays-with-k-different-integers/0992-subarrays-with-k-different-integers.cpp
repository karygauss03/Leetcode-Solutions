class Solution {
private:
    int solve(vector<int>& arr, int k)
    {
        int n = arr.size();
        int count = 0, left = 0, right = 0;
        unordered_map<int,int> map;
        while (right < n) {
            if (map.find(arr[right])==map.end())
                map[arr[right]]=0;
            map[arr[right]]++;

            while (map.size() > k) {
                map[arr[left]]= map[arr[left]] - 1;
                if (map[arr[left]] == 0)
                    map.erase(arr[left]);
                left++;
            }

            count += right - left + 1;
            right++;
        }
        return count;
    }

public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return solve(nums, k) - solve(nums, k - 1);
    }
};