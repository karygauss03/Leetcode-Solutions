class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {
        int n=arr.size();
        if (n<4) //There is exactly one integer occurs more than 25%
            return arr[0];
        int x[5]={arr[0], arr[n/4], arr[n/2], arr[3*n/4], arr[n-1]};
        for (int i=0; i<4; i++)
            if (x[i]==x[i+1]) return x[i];

        //If not found, proceed the binary search
        int q[5]={0, n/4, n/2, 3*n/4, n-1};
        for (int i=1; i<3; i++){
            int r=upper_bound(arr.begin()+q[i-1], arr.begin()+q[i+1]+1, x[i])-arr.begin()-1;
            int l=lower_bound(arr.begin()+q[i-1], arr.begin()+q[i+1]+1, x[i])-arr.begin();
            if (r-l+1>n/4) return x[i];
        }
        
        return x[3];
    }
};