class Solution:
    def sortedSquares(self, A: List[int]) -> List[int]:
        
        # seperate A to two list, [negtive], and [non-negtive]
        left,right = 0,len(A)-1
        
        while left < right:
            mid = left+(right-left)//2
            if A[mid]>=0:
                right = mid
            else:
                left = mid+1
        
        output=[]
        
        #i,j for lef, right pointers
        #use these two pointers to generate answer list
        
        i = left-1
        j = left
        while 0<=i and j<len(A):
            templeft = A[i]**2
            tempright=A[j]**2
            if templeft<tempright:
                output.append(templeft)
                i -=1
            else:
                output.append(tempright)
                j+=1
        
        while i>=0: # if leftside is longer
            output.append(A[i]**2)
            i-=1
        while j<len(A):
            output.append(A[j]**2)
            j +=1
            
        return output