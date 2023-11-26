#pragma GCC optimize("O3")
class Solution {
public:  
    int largestSubmatrix(vector<vector<int>>& matrix) {
        int m=matrix.size(), n=matrix[0].size();
        int area=count(matrix[0].begin(), matrix[0].end(), 1);
        if (m==1) return area;
        if (n==1){
            #pragma unroll
            for(int i=1; i<m; i++){
                if (matrix[i][0]!=0)
                    matrix[i][0]+=matrix[i-1][0];
                area=max(area, matrix[i][0]);
            }
            return area;
        }
        
        #pragma unroll
        for(int i=1; i<m; i++){
            #pragma unroll
            for(int j=0;  j<n; j++){
                if (matrix[i][j]!=0)
                    matrix[i][j]+=matrix[i-1][j];
            }
       
            auto row=matrix[i];
            int minH=i+1, maxH=0;
            #pragma unroll
            for(int x: row){
                minH=min(minH, x);
                maxH=max(maxH, x);
            }
            vector<int> freq(maxH-minH+1, 0);
            #pragma unroll
            for(int x: row){
                freq[x-minH]++;
            }
            int acc=0;
            #pragma unroll
            for(int x=maxH-minH; acc<n; x--){
                if (freq[x]>0){
                    acc+=freq[x];
                    area=max(area, acc*(x+minH));
                }
            }  
        }
        return area;
    }
};