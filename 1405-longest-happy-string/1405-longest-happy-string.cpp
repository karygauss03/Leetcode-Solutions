class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        priority_queue<pair<int, char>> pq;
        if (a > 0) pq.push({a, 'a'});
        if (b > 0) pq.push({b, 'b'});
        if (c > 0) pq.push({c, 'c'});

        string ans = "";

        while (!pq.empty()) {
            auto mx = pq.top();
            pq.pop();

            // Check for consecutive characters
            int n = ans.size();
            if (n >= 2 && ans[n - 1] == mx.second && ans[n - 2] == mx.second) {
                // If we cannot use mx, we need to use the next character
                if (pq.empty()) break;  // If there's nothing left to use, we break

                auto mx2 = pq.top();
                pq.pop();

                // Add the second most frequent character
                ans += mx2.second;
                mx2.first--;

                // Push back the second character if there are remaining counts
                if (mx2.first > 0) pq.push(mx2);

                // Push mx back for the next round
                pq.push(mx); 
            } else {
                // We can safely add the most frequent character
                if (mx.first >= 2) {
                    ans += mx.second;
                    ans += mx.second;
                    mx.first -= 2;
                } else {
                    // Add whatever is left if it's only one
                    ans += mx.second;
                    mx.first--;
                }

                // Push back the character if there are remaining counts
                if (mx.first > 0) pq.push(mx);
            }
        }

        return ans;
    }
};
