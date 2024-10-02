class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        set<pair<int, int>> st;
        for (int i = 0; i < arr.size(); ++i) {
            st.insert(make_pair(arr[i], i));
        }
        int rank = 0;
        int lastValue = INT_MIN;
        while (!st.empty()) {
            auto p = st.begin();
            if (p->first == lastValue) {
                arr[p->second] = rank;
            }
            else {
                ++rank;
                arr[p->second] = rank;
                lastValue = p->first;
            }
            st.erase(p);
        }
        return arr;
    }
};