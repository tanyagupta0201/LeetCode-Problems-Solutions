# Name - Harshit Mehra 
# Date - 03/10/2022

class Solution:
    def removeDuplicates(self, nums: List[int]) -> int:
        nums[:] = list(set(nums))
        nums.sort()
        return len(nums)
