class Solution {
public:
    int minimumDeviation(vector<int>& nums) {
        // Step 1:- Increase all elements to as maximum as it can and track the minimum number and also the result.
        int n = nums.size();
        int maxx = INT_MIN, minn = INT_MAX;
        for(int i=0; i<n; i++){
            if(nums[i]%2 == 1)
                nums[i] = nums[i]*2;
            maxx = max(maxx, nums[i]);
            minn = min(minn, nums[i]);
        }
        int min_deviation = maxx - minn;
        
        //Step 2:- Insert into max_heap and try to decrease the maxx as much as you can
        priority_queue<int> pq;
        for(int i=0; i<n; i++){
            pq.push(nums[i]);
        }
        
        while((pq.top())%2 == 0){
            int top = pq.top();
            pq.pop();
            min_deviation = min(min_deviation, top - minn);
            top = top/2;
            minn = min(minn, top);
            pq.push(top);
        }
        min_deviation = min(min_deviation, pq.top() - minn);
        
        //Step 3:- return maxx - minn
        return min_deviation;
    }
};