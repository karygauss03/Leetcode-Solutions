class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        vector<string> morse={".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
        string ans="";
        set<string> ss;
        for (int i=0;i<words.size();i++){
            ans="";
            for (int j=0;j<words[i].size();j++){
                ans+=morse[words[i][j]-'a'];
            }
            ss.insert(ans);
        }
        return (ss.size());
    }
};