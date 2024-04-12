class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int leftMax = INT_MIN, rightMax = INT_MIN;
        int l = 0, r = n - 1;
        int ans = 0;
        
        while (l <= r){
            if (height[l] <= height[r]){
                if (height[l] > leftMax){
                    leftMax = height[l];
                }
                else{
                    ans += leftMax - height[l];
                }
                l++;
            }
            else {
                if (height[r] > rightMax){
                    rightMax = height[r];
                }
                else {
                    ans += rightMax - height[r];
                }
                r--;
            }
        }
        return ans;
    }
};