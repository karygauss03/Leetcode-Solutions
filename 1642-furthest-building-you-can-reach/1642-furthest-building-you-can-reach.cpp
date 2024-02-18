class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        int n = heights.size() ;
        priority_queue<int,vector<int>,greater<int>> pq ;
        int index = 1 ;
        while(index<n){            
            if(heights[index]-heights[index-1] > 0){
                pq.push(heights[index]-heights[index-1]);
            }
            if(pq.size() > ladders)
            {
                bricks -= pq.top();
                pq.pop();
                if(bricks < 0){
                    return index-1 ;
                }
            }
            index++;                    
        }
        return index-1 ;
    }
};