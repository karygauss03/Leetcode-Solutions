class Solution {
public:
    long long totalCost(vector<int>& costs, int k, int candidates) {
        long long ans = 0;
        priority_queue<int, vector<int>, greater<int>> q1;  
        priority_queue<int, vector<int>, greater<int>> q2; 
        int low = 0;  
        while (low < candidates) {
            q1.push(costs[low]);
            low++;
        }

        int cnt = 0;
        int high = (int)costs.size() - 1;  

        if (candidates > costs.size() - candidates) {
            candidates = costs.size() - candidates;
        }  

        while (cnt < candidates) {
            q2.push(costs[high]);
            cnt++;
            high--;
        }    

        while (k--) {
            if (q1.empty()) {
                ans += q2.top();
                q2.pop();
                if (low <= high) {
                    q2.push(costs[high]);
                    high--;
                }        
            } else if (q2.empty()) {
                ans += q1.top();
                q1.pop();
                if (low <= high) {
                    q1.push(costs[low]);
                    low++;
                } 
            } else if (q1.top() <= q2.top()) { 
                ans += q1.top();
                q1.pop();
                if (low <= high) {
                    q1.push(costs[low]);
                    low++;
                }
            } else { 
                ans += q2.top();
                q2.pop();
                if (low <= high) {
                    q2.push(costs[high]);
                    high--;
                }           
            }
        }
        return ans;
    }
};