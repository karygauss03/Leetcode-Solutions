class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        int n = profits.size(), finalCapital = w;
        priority_queue<pair<int, int>> q;
        int capitalIndex = 0;
        // store both profits and capital in sorted order of capital
        vector<pair<int, int>> arr;

        for (int i = 0; i < n; i++)
            arr.push_back({capital[i], profits[i]});

        sort(arr.begin(), arr.end());
        for (int i = 0; i < n; i++)
        {
            auto [cap, profit] = arr[i];
            if (cap <= w)
            {
                q.emplace(profit, cap);
                capitalIndex++;
            }
            else
                break;
        }
        int projects = 0;

        while (!q.empty() && projects < k)
        {
            auto [profit, capitalReq] = q.top(); q.pop();
            finalCapital += profit;
            // make sure we don't take too many projects
            projects++;
            // add potential projects if we can take them on
            while (capitalIndex < n && finalCapital >= arr[capitalIndex].first)
            {
                auto [cap, prof] = arr[capitalIndex];
                q.emplace(prof, cap);
                capitalIndex++;
            }
        }
        return finalCapital;
    }
};