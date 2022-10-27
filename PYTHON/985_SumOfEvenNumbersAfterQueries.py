# NAME : Shubham Arora
# Date : 23/Oct/2022

class Solution:
    def sumEvenAfterQueries(self, nums: List[int], queries: List[List[int]]) -> List[int]:
        l = len(nums)
        m = len(queries)
        
        # Initially finding the sum of all the even numbers
        o = sum([i for i in nums if i % 2 == 0])
        k = nums
        x = []
        
        for i in queries:
            w = k[i[1]]
            # performing the required addition operation
            k[i[1]] = k[i[1]] + i[0]
            
            # subtracting the number from the list if it was initially even
            if w % 2 == 0:
                o -= w
            # checking if the new number is even
            if k[i[1]] % 2 == 0:
                o += k[i[1]]
            x.append(o)
        # returning the list
        return x
            
            
        
            
            
            
        
            
