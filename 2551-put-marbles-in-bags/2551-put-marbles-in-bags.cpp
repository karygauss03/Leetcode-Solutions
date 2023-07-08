class Solution {
public:
    long long putMarbles(vector<int>& weights, int k) {
        int n=weights.size();
        if(n==k || k==1){
            return 0;
        }
        else{
            long long sum[n-1];
            long long MAX=0,MIN=0;
            for(int i=0;i<=n-2;i++){
                sum[i]=weights[i]+weights[i+1];
            }
            sort(sum,sum+(n-1));
            for(int j=0;j<k-1;j++){
                MAX=MAX+sum[n-2-j];
                MIN=MIN+sum[j];
            }
            return MAX-MIN;
        }
    }
};