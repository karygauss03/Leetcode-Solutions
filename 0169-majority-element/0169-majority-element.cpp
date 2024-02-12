class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count = 0;
        int majorNum = 0;
        for(auto num: nums) {
            if(count == 0)
                majorNum = num;
            
            if(num == majorNum) {
                count++;
            } else {
                count--;
            }
        }
        
        return majorNum;
    }
};