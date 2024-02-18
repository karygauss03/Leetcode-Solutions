class Solution
{
public:
    int mostBooked(int n, vector<vector<int>> &meetings)
    {
        vector<int> ans(n, 0);
        priority_queue<int, vector<int>, greater<int>> available;
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> busy;
        
        
        for (int i = 0; i < n; i++)
        {
            available.push(i);
        }
        
     
        sort(meetings.begin(), meetings.end());

        for (auto &&meeting : meetings)
        {
            int start = meeting[0], end = meeting[1];

            while (busy.size() > 0 && busy.top().first <= start)
            {
                available.push(busy.top().second);
                busy.pop();
            }

       
            if (available.size() > 0)
            {
                int top = available.top();
                ans[top]++;
                available.pop(); 
                busy.push({end, top});
            }
            else
            {
                auto top = busy.top();
                int end1 = top.first, index = top.second;

                ans[index]++;
                busy.pop();
                busy.push({top.first + end - start, index});
            }
        }

     
        return max_element(ans.begin(), ans.end()) - ans.begin();
    }
};