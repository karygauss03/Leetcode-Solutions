class Solution {
public:
    string customSortString(string order, string str) {
        int hashTab [26] = {0};
        for (auto x : str){
            hashTab[x - 'a'] ++;
        }
        
        int j = 0;
        for (int i=0 ;i<order.size();i++){
            while (hashTab[order[i] - 'a']){
                hashTab[order[i] - 'a'] --;
                str[j++] = order[i];
            }
        }
        
        for (int i=0;i<26;i++){
            while(hashTab[i]--){
                str[j++] = i + 'a';
            }
        }
        
        
        return str;
    }
};