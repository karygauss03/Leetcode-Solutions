class Solution {
public:
    vector<long long> mostFrequentIDs(vector<int>& nums, vector<int>& freq) {
        unordered_map<int, long long> idToFrequency;
        map<long long, int> frequencyToIdsCount;
        vector<long long> ans;
        for (int i = 0; i < nums.size(); ++i) {
            if (idToFrequency[nums[i]]) {
                frequencyToIdsCount[idToFrequency[nums[i]]]--;
                if (frequencyToIdsCount[idToFrequency[nums[i]]] == 0) {
                    frequencyToIdsCount.erase(idToFrequency[nums[i]]);
                }
            }
            idToFrequency[nums[i]] += freq[i];
            frequencyToIdsCount[idToFrequency[nums[i]]]++;
            ans.push_back(frequencyToIdsCount.rbegin()->first);
        }
        return ans;
    }
};