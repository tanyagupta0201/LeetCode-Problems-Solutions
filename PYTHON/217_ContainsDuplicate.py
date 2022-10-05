# Name: Srikar MK
# Date: 03/10/2022

class Solution:
    def containsDuplicate(self, nums: List[int]) -> bool:
        final = set()        
        for i in nums:
            if i in final:
                return True
            final.add(i)
        return 
