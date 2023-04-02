class Solution {
public:
    int binarySearch(int spell, vector<int>& potions, long long success) {
        int startIndex = 0; 
        int lastIndex = potions.size() - 1;
        while(startIndex <= lastIndex){
            int midIndex = (startIndex + (lastIndex - startIndex) / 2);
            if ((long long) spell * potions[midIndex] >= success){
                lastIndex = midIndex - 1;
            }
            else{
                startIndex = midIndex + 1;
            }
        }
        return lastIndex + 1;   
    }
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        sort(potions.begin(), potions.end());
        int m = potions.size();
        vector<int> ans;
        for (int spell : spells) {
            int index = binarySearch(spell, potions, success);
            ans.push_back(m - index);
        }
        return ans;
    }
};