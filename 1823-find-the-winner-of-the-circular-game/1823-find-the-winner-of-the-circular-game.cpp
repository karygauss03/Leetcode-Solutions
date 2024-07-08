class Solution {
public:
    int findTheWinner(int n, int k) {
        queue<int> q;
        for(int i=1;i<=n;++i){q.push(i);}
        while(q.size()>=2){
            for(int i=0;i<k-1;++i){
                int f = q.front();
                q.pop();
                q.push(f);
            }
            q.pop();
        }
        return q.front();
    }
};