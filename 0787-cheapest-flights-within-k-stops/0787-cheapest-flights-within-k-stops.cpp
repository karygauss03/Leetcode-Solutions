class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {
        unordered_map<int,vector<pair<int, int>>> adjList;
        for( auto f : flights )
            adjList[f[0]].push_back( { f[1], f[2] } );
        
        priority_queue< vector<int>, vector<vector<int>>, greater<vector<int>> > minHeap;
        minHeap.push( { 0, src, 0 } );
        
        vector<int> dist(n+1, INT_MAX);
        while( !minHeap.empty() ) {
            auto t = minHeap.top(); minHeap.pop();
            int cost = t[0];
            int curr = t[1];
            int stop = t[2];
            
            if( curr == dst )
                return cost;
            
            if(dist[curr]<stop) continue;
                 dist[curr]=stop;

            if(stop >K ) continue;
            
                for( auto next : adjList[curr] )
                    minHeap.push( { cost+next.second, next.first, stop+1 });
        }
        return -1;
    }
};