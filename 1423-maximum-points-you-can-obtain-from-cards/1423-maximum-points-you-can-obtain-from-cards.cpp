class Solution {
public:
    int maxScore(vector<int>& nums, int k) {
        if(k == nums.size()){
            int temp = 0;
            for(int i=0; i<nums.size(); i++)
                temp += nums[i];
            return temp;
        }
            
        
        int i=k-1,j = k-1;
        int sum = 0;
        int ans = 0;
        while(i>=0){
            sum+=nums[i];
            i--;
        }
        
        ans = sum;
        i=nums.size()-1;
        
        while(j>=0){
            sum = sum - nums[j] + nums[i];
            ans = max(ans,sum);
            j--;i--;
        }
        
        return ans;
    }
};