class Solution {
public:
int maxSumSubmatrix(vector<vector<int>> &matrix,int k)
{
    int n=matrix.size(),m=matrix[0].size(),ans=INT_MIN;
    for(int i=0;i<m;i++){
        vector<int> preSum(n,0);
        for(int j=i;j<m;j++){
            set<int> st;
            st.insert(0);
            int cur=0;
            for(int z=0;z<n;z++){
                cur+=matrix[z][j];
                preSum[z]+=cur;
                auto it=st.lower_bound(preSum[z]-k);
                if(it!=st.end()) ans=max(ans,preSum[z]-*(it));
                st.insert(preSum[z]);
            }
        }
    }
    if(ans!=INT_MIN) return ans;
    return -1;
}
};