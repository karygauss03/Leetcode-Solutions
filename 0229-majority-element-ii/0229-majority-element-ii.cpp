class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int> counted;
        vector<int> ans;
        int n=nums.size();
        for (int i=0;i<n;i++){
            auto it = find(counted.begin(), counted.end(), nums[i]);
            if (it==counted.end()){
                counted.push_back(nums[i]);
            }
        }
        int m=counted.size();
        for (int i=0;i<m;i++){
            int x=count(nums.begin(),nums.end(),counted[i]);
            if (x>n/3){
                ans.push_back(counted[i]);
            }
        }
        return ans;
    }
};