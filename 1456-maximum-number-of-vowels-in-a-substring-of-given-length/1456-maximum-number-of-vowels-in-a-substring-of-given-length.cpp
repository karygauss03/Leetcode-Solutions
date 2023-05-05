bool isVowel(char &c) {
  if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') return true;
  return false;
}

class Solution {
  public: int maxVowels(string s, int k) {
    int n = s.size();
    int i;
    int max_vow = 0;
    int count = 0;
    for (i = 0; i < n; ++i) {
      if (isVowel(s[i]))
        count++;
      if (i >= k - 1) {
        max_vow = max(max_vow, count);
        if (isVowel(s[i - k + 1]))
          count--;
      }
    }

    return max_vow;
  }
};