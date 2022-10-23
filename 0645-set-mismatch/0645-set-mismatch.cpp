class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        vector<int>ans;
        sort(nums.begin(),nums.end());
        int a=0,b=0;
        for(int i=1;i<nums.size();i++ ){
            if(nums[i]==nums[i-1]){
                a=nums[i];
                break;
            }
        }
        for(int i=1;i<=nums.size();i++){
            if(!binary_search(nums.begin(),nums.end(),i)){
                b=i;
                break;
            }
        }
        return {a,b};
    }
};