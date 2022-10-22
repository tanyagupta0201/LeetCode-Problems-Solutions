# NAME : Shubham Arora
# DATE : 22/Oct/2022
class Solution:
    def partitionArray(self, nums: List[int], k: int) -> int:
        # Sorting the list to find the difference of adjacent elements easily
        nums.sort()
        ans = 1
        start = nums[0]
        for i in range(1, len(nums)):
            # finding the difference and checking it with k
            diff = nums[i] - start
            if diff > k:
                # incrementing the counter
                ans += 1
                start = nums[i] 
        # returning the final output
        return ans