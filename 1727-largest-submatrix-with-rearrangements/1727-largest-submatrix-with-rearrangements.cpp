#pragma GCC optimize("O3")
class Solution {
public:  
    int largestSubmatrix(vector<vector<int>>& matrix) {
        int m=matrix.size(), n=matrix[0].size();
        int area=count(matrix[0].begin(), matrix[0].end(), 1);
        #pragma unroll
        for(int j=0; j<n; j++){
            #pragma unroll
            for(int i=1;  i<m; i++){
                if (matrix[i][j]!=0)
                    matrix[i][j]+=matrix[i-1][j];
            }
        }
        unordered_map<int, int> freq;
        #pragma unroll
        for(int i=0;  i<m; i++){
            auto row=matrix[i];
            freq.clear();
            int maxH=0;
            #pragma unroll
            for(int x: row){
                maxH=max(maxH, x);
                freq[x]++;
            }
            int acc=0;
            #pragma unroll
            for(int x=maxH; acc<n; x--){
                if (freq.count(x)>0){
                    acc+=freq[x];
                    area=max(area, acc*x);
                }
            }  
        }
        return area;
    }
};