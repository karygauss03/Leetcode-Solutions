class Solution {
public:
  vector<int> sumEvenAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
    int evenSum = 0;
    for (const int& num : nums) {
      if (num % 2 == 0)
        evenSum += num;
    }
    
    vector<int> result;
    for (const auto& q : queries) {
      int val = q[0], i = q[1];
      if (nums[i] % 2 == 0) {
        if (val % 2 == 0)
          evenSum += val;
        else
          evenSum -= nums[i];
      }
      else {
        if (val % 2 == 0)
          ;
        else
          evenSum += val + nums[i];
      }
      nums[i] += val;
      
      result.emplace_back(evenSum);
    }
    
    return result;
  }
};