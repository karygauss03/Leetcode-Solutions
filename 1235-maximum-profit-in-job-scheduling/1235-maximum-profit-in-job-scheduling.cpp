class Solution {
public:
    int dp[50005];
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        vector<pair<pair<int, int>, int>> jobs; //jobs[i] = {{s, e}, p}
        for (int i = 0 ; i < startTime.size() ; i++){
            jobs.push_back(make_pair(make_pair(startTime[i], endTime[i]), profit[i]));
        }
        sort(jobs.begin(), jobs.end());
        for (int i = 0 ; i < jobs.size() ; i++){
            startTime[i] = jobs[i].first.first;
            endTime[i] = jobs[i].first.second;
            profit[i] = jobs[i].second;
        }
        for (int i = jobs.size() - 1 ; i >= 0 ; i--){ //going from the end since there might be jobs who has equal endime and starting time so if we go from i==0 then we are gonna miss the next endtime which has the maximum profit
            int s = startTime[i];
            int e = endTime[i];
            int p = profit[i];
            auto it = lower_bound(startTime.begin(), startTime.end(), e); //for the ith endtime checking the next i+jth startime which is equal or greater than current endtime
            int idx = it - startTime.begin(); //finding the index of the targeted job
            if (it != startTime.end()){ //suppose we found a job whose start time is equal or greater than current endtime
                int j = idx;
                p += dp[j]; //so we add the profit of the job which starts after the end of the current job and  whose end time is not overlapping
            }
            if (i == jobs.size() - 1){
                dp[i] = p;
            }
            else {
                dp[i] = max(dp[i + 1], p); //we take the ith element or we don't and replace the ith element with i+1th element if the  profit is greater than taking the ith job
            }
        }
        return dp[0];
    }
};