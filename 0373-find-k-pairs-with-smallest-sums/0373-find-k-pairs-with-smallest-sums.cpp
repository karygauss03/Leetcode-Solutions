class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        priority_queue<pair<int , pair<int , int>> , vector<pair<int , pair<int , int>>>>q;
        long long int sum=0;
        vector<vector<int>>ans;
        for(auto n : nums1)
        {
            for(auto m : nums2)
            {
                sum = n+m;
                if(q.size() < k)q.push({sum , {n , m}});
                else if(q.top().first > sum)
                {
                    q.pop();
                    q.push({sum , {n , m}});
                }
                else break;
            }
        }
        vector<int>temp;
        while(!q.empty())
        {
            temp.push_back(q.top().second.first);
            temp.push_back(q.top().second.second);
            ans.push_back(temp);
            q.pop();
            temp.clear();
        }
        reverse(ans.begin() , ans.end());
        return ans;
    }
};