# Name: Swapnanil Ray
# Date: 03/10/2022

class Solution:
    def decompressRLElist(self, nums: List[int]) -> List[int]:
        finalList = []
        for i in range(0,len(nums),2):
            freq = nums[i]
            val = nums[i+1]
            res = [val]*freq
            finalList = finalList + res
            
        return finalList
        