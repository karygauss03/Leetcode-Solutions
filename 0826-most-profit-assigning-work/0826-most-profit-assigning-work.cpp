class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        vector<pair<int, int>> jobs;
        for (int i = 0; i < profit.size(); ++i) {
            jobs.push_back(make_pair(profit[i], difficulty[i]));
        }
        sort(jobs.rbegin(), jobs.rend());
        int ans = 0;
        for (int i = 0; i < worker.size(); ++i) {
            int j = 0;
            while (j < profit.size()) {
                if (jobs[j].second <= worker[i]) {
                    ans += jobs[j].first;
                    break;
                }
                ++j;
            }
        }
        return ans;
    }
};