class Solution {
private:
    vector<pair<int, string>> freq2;
    map<string, int> freq;
    vector<string> ans;
    bool static cmp(const pair<int, string> &a, const pair<int, string> &b){
        if (a.first != b.first) return a.first < b.first;
        return a.second > b.second;
    }
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        for (auto &s : words){
            freq[s]++;
        }
        for (auto &fr : freq){
            freq2.push_back(make_pair(fr.second, fr.first));
        }
        sort(freq2.rbegin(), freq2.rend(), cmp);
        for (int i = 0 ; i < k ; i++){
            ans.push_back(freq2[i].second);
        }
        return ans;
    }
};