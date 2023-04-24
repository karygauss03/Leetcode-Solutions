class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int, vector<int>, less<int>> pq(stones.begin(), stones.end());
        
        while(pq.size() > 1){
            int x = pq.top(); pq.pop(); 
            int y = pq.top(); pq.pop(); 
            if (x < y) pq.push(y-x);
            else pq.push(x-y);
        }
        return pq.top();
    }
};