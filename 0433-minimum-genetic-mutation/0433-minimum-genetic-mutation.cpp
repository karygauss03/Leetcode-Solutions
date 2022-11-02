class Solution {
public:
    int minMutation(string start, string end, vector<string>& bank) {
        unordered_set<string> st(bank.begin(), bank.end());
        char choices[] = {'A', 'C', 'G', 'T'};
        queue<pair<string, int> > q;
        q.push({start, 0});
        st.erase(start);
        while(!q.empty()){
            string word = q.front().first;
            int m = q.front().second;
            q.pop();
            if(word == end)
                return m;
            for(int i=0; i<word.length(); i++){
                string temp = word;
                for(auto ch : choices){
                    word[i] = ch;
                    if(st.find(word) != st.end()){
                        st.erase(word);
                        q.push({word, m+1});
                    }
                }
                word = temp;
            }
        }
        return -1;
    }
};