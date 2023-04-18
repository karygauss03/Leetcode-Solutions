class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int n1=word1.size();
        int n2=word2.size();
        string ans="";
        int i=0,j=0;
        int cnt=0;
        while (i<min(n1,n2) || j<min(n1,n2)){
            if (cnt%2==0){
                ans+=word1[i];
                i++;
            }
            if (cnt%2!=0){
                ans+=word2[j];
                j++;
            }
            cnt++;
        }
        while (i<n1){
            ans+=word1[i];
            i++;
        }
        while (j<n2) {
            ans+=word2[j];
            j++;
        }
        return ans;
    }
};