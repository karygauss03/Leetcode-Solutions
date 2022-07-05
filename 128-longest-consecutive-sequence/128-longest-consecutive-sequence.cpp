class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int maxi = 0;
        unordered_set<int> s(nums.begin(), nums.end());
        for(int i = 0 ; i < nums.size() ; i++)
        {
            if(s.count(nums[i] - 1) == 0)
            {
                int c = 0;
                int k = nums[i];
                while(s.count(k))
                {
                    c++;
                    k++;
                }
                maxi = max(maxi, c);
            }
        }
        return maxi;
    }
};