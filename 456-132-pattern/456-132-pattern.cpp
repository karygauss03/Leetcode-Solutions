class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        stack<pair<int , int>> st; 
        int currMin = nums[0]; 
        for(int i=1;i<nums.size();i++) 
        {
            while(!st.empty() && nums[i]>=st.top().first) 
                st.pop();
            if(!st.empty() && nums[i]>st.top().second) 
                return true; 
            st.push({nums[i],currMin}); 
            currMin = min(currMin,nums[i]); 
        }
        return false;
    }
};