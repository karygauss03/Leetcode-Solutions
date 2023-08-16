class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
      priority_queue<pair<int,int>>pq;
      vector<int>ans;
      for(int i=0;i<nums.size();i++){
          pq.push({nums[i],i});
          if(i>=(k-1)){
              while(i - pq.top().second >= k){
                  pq.pop();
              }
              ans.push_back(pq.top().first);
          }
      }  
      return ans;
    }
};