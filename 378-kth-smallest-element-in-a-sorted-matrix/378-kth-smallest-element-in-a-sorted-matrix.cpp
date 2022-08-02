class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int len = matrix.size();
        int low = matrix[0][0],high = matrix[len-1][matrix[0].size()-1],mid,count;
       
        while(low<high){
             mid = low+(high-low)/2;
                count=0;
            for(int i=0;i<len;i++){
                count+= upper_bound(matrix[i].begin(),matrix[i].end(),mid) - matrix[i].begin();
                // cout<<low<<" "<<high<<" "<<count<<" "<<mid<<endl;
            }
            if(count<k){
                low=mid+1;
            } else {
                high = mid;
            }
        }
        
        return low;
    }
};