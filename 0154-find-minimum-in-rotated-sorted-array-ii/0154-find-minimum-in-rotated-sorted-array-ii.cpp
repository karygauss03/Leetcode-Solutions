class Solution {
public:
    int findMin(vector<int>& nums) {
         int left = 0, right = nums.size()-1;
        while (left < right) {
            int mid = left+(right-left)/2;
            if (nums[left] > nums[mid]){ 
                left++;
                right=mid;
            }
            else if (nums[mid] > nums[right]){ 
                left=mid+1;
            }
            else {
                if(nums[left] < nums[right])
                    return nums[left];
                else
                    right--;
            }
        }
        return nums[left];
    }
};