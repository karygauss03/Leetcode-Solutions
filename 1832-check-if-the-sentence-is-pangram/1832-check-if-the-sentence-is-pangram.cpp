class Solution {
private:
    int freq[26];
public:
    bool checkIfPangram(string sentence) {
        for (char &c : sentence){
            freq[c - 'a']++;
        }
        for (int i = 0 ; i < 26 ; i++){
            if (!freq[i]) return false;
        }
        return true;
    }
};