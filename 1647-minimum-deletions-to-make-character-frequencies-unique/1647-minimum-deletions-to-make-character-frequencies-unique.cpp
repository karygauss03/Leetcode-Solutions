class Solution {
public:
    int minDeletions(string s) {
        vector<int>v(26,0);
            for(auto &c:s){
                    v[c-'a']++;//store the frequency of each element of string 
            } 
            sort(v.begin(),v.end());//sort the array in increasing order
            int count=0;
            
            for(int i=24;i>=0;i--){
                    if(v[i]==0)break; //run the loop and check if v[i] greater than or equal to i+1
                    
                    while(v[i] && v[i]>=v[i+1]){
                            v[i]--;   //decrement v and increment count
                            count++;
                    }
            }
            return count;
        
    }
};