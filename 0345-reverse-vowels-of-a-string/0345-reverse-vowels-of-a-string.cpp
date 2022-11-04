class Solution {
public:
  string reverseVowels(string s) {
    int p1 = 0;
    int p2 = s.size() - 1;

    while (p1 < p2) {
      if (s[p1] == 'a' || s[p1] == 'e' || s[p1] == 'i' || s[p1] == 'o' || s[p1] == 'u' || s[p1] == 'A' || s[p1] == 'E' || s[p1] == 'I' ||
          s[p1] == 'O' || s[p1] == 'U') {
        if (s[p2] == 'a' || s[p2] == 'e' || s[p2] == 'i' || s[p2] == 'o' || s[p2] == 'u' || s[p2] == 'A' || s[p2] == 'E' || s[p2] == 'I' ||
            s[p2] == 'O' || s[p2] == 'U') {
          swap(s[p1], s[p2]);
          p1++;
          p2--;
        } else {
          p2--;
        }
      } else {
        p1++;
      }
    }

    return s;
  }
};