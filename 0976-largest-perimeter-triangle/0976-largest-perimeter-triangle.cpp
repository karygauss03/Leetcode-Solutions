class Solution {
public:
    int largestPerimeter(vector<int>& nums) {  // largest perimeter triangle
        int n=nums.size();  // size of vector
        sort(nums.begin(),nums.end());  // sort the vector
        for(int i=n-1;i>=2;i--){    // loop for vector
            if(nums[i]<nums[i-1]+nums[i-2]){    // if condition is true
                return nums[i]+nums[i-1]+nums[i-2]; // return sum
            }
        }
        return 0;   // return zero
    }
};