class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        if (deck.size() == 1) {
            return deck;
        }
        
        if (deck.size() == 2) {
            return {min(deck[0], deck[1]), max(deck[0], deck[1])};
        }
        vector<int > ans;
        queue<int> q;
        sort(deck.begin(), deck.end());
        int i = deck.size() - 1;
        q.push(deck[i--]);
        q.push(deck[i--]);
        while (i >= 0) {
            int frontElement = q.front();
            q.pop();
            q.push(frontElement);
            q.push(deck[i--]);
        }
        while (!q.empty()) {
            ans.insert(ans.begin(), q.front());
            q.pop();
        }
        return ans;
    }
};