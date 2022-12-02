class Solution:
    def longestPalindrome(self, s: str) -> int:
        n = len (s)
        occ = {}
        longueur = 0
        # aabac
        for i in range(n):
            if (s[i] in occ):
                occ[s[i]] += 1
            else:
                occ[s[i]] = 1
        for x in occ.values():
            if x % 2 == 0 :
                longueur += x
            else:
                longueur += x - 1
        if longueur != n:
            longueur = longueur + 1
        return longueur