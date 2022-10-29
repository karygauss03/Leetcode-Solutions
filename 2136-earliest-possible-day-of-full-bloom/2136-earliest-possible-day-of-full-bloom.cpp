class comp{
  public:
    bool operator()(pair<int,int>&p1,pair<int,int>&p2){
        return p1.first<p2.first;
    }
};
class Solution {
public:
    int earliestFullBloom(vector<int>& plantTime, vector<int>& growTime) {
        priority_queue<pair<int,int>,vector<pair<int,int>>,comp> pq; 
        for(int i=0;i<growTime.size();i++){  // store maxGrowTime with their index
            pq.push({growTime[i],i});
        }
        int mxPlantTime = 0; // Store mamimum plant time
        int mxGrowTime = 0; // store maximum grow time
        while(pq.size()){   // One by one take maximum grow time flower from queue
            pair<int,int> p = pq.top();
            mxPlantTime+=plantTime[p.second]; // track of maximum plant time
            mxGrowTime = max(mxGrowTime,mxPlantTime+p.first); // track of maximum grow time
            pq.pop();
        }
        return mxGrowTime; 
    }
};