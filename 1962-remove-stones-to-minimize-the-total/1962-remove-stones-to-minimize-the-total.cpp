class Solution {
public:
      int minStoneSum(vector<int>& piles, int k) {
        priority_queue<int>pq(piles.begin(),piles.end()); //will copy the vector to the priority queue 
        int ans=0;
        for(int i=0;i<k;i++){
            int tp=pq.top(); //top element will always be the largest element
            pq.pop();
            tp-=(tp/2);   
            pq.push(tp);
        }
        while(!pq.empty()){
            ans+=pq.top();   //adding the left stones, after k operations
            pq.pop();
        }
        return ans;
    }
};