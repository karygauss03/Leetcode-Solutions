class Solution {
public:
    string convertToTitle(int columnNumber) {
        int n = columnNumber;
        string ans;
        while (n > 0) {
            n--;
            auto [q, r] = div(n, 26);
            ans.push_back(char('A'+r));
            n = q;
        }
        reverse(ans.begin(), ans.end()); // Reverse the ans string
        return ans; // Return the reversed ans string
    }
};