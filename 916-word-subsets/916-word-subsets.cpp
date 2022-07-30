// Time complexity: O(10*m + (26+10)*n + 26*n) = O(m+n)
// Space complexity: O(26*m + 26) = O(m)


class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        //for a string to be universal it should have all w2 as subsets
        //that means max of each character from each string
        vector<vector<int>> w1(words1.size(), vector<int>(26, 0));
        vector<int> w2(26, 0);

        for (int i=0; i<words1.size(); i++){
            for (int j=0; j<words1[i].length(); j++) w1[i][words1[i][j] - 'a']++;
        }

        for (int i=0; i<words2.size(); i++){
            vector<int> w3(26, 0);
            for (int j=0; j<words2[i].length(); j++){
                w3[words2[i][j] - 'a']++;
            }
            // save the max amount of all chars in words2
            for (int i=0; i<26; i++) w2[i] = max(w2[i], w3[i]);
        }

        vector<string> res;
        for (int i=0; i<w1.size(); i++){
            // see if every word2 is a subset of this word1
            // if every char of word has equal or more amount of combined chars
            int universal = true;
            for (int k=0; k<26; k++){
                if (w1[i][k] < w2[k]){
                    universal = false;
                }
            }
            if (universal) res.push_back(words1[i]);
        }
        return res;
    }
};