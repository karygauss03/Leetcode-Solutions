from collections import Counter

class Solution:
    def commonChars(self, A: List[str]) -> List[str]:
        res = Counter(A[0])
        
        for a in A:
            res &= Counter(a)
        
        return res.elements()