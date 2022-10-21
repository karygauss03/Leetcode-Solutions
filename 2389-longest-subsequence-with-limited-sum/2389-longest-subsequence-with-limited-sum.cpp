/*

    Since we want to find the subarray sum that satisfies the condition, we can
    sort all the numbers and then find their cummulative sum. This ensures that we
    get cummulative sum in ascending order.
    Then using binary search we look for the 1st sum that is greater than the query number.
    The distance from 0th index to that index-1 is the length of the longest such subarray.
    
*/
class Solution {
public:
    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
        sort(nums.begin(), nums.end());
        vector<long long> cumm_sum(nums.size(), 0);
        
        // find the cummulative sum
        for(int i = 0; i < nums.size(); i++)
            cumm_sum[i] =  nums[i] + (i > 0 ? cumm_sum[i-1] : 0);
        
        vector<int> result(queries.size(), 0);
        for(int i = 0; i < queries.size(); i++) {
            // Find the position of the subarray sum just greater than current
            auto it = upper_bound(cumm_sum.begin(), cumm_sum.end(), queries[i]);
            // position distance from 0
            int dist = distance(cumm_sum.begin(), it);
            // No cummulative sum smaller than query found
            if(it == cumm_sum.begin())
                result[i] = 0;
            // When all the nums can be used
            else if(it == cumm_sum.end())
                result[i] = cumm_sum.size();
            else
                result[i] = dist;
        }
        return result;
    }
};