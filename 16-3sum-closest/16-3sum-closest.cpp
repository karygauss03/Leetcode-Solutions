class Solution {
public:
  int threeSumClosest(vector<int>& nums, int target) {
    int rest = INT_MAX, n = nums.size(), r_start = nums.size() - 1, answer;
    sort(nums.begin(), nums.end());
    
    for (int i = 0; i < n; i++){
      int l = i + 1, r = r_start;
      
      while(l < r){
        int s = nums[i] + nums[l] + nums[r];
        int dif = abs(target - s);
        
        if (dif < rest)
          if(dif) rest = dif, answer = s;
          else return s;
        
        if (s < target) l++;
        else r--;
      }
    }
    
    return answer;
  }
};
