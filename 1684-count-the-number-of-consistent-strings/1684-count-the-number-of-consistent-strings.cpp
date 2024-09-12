class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        int ans=0;
        map<char,int> ma;
        for (int i=0;i<allowed.size();i++){
            ma[allowed[i]]++;
        }
        for (int i=0;i<words.size();i++){
            bool flag=true;
            for (int j=0;j<words[i].size();j++){
                if (ma[words[i][j]]==0){
                    flag=false;
                    break;
                }
            }
            if (flag) ans++;
        }
        return ans;
    }
};