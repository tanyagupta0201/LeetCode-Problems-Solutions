class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        result = max(nums)
        if result<=0:
            return result
        
        sum = 0
        for i in nums:
            sum = max(sum+i,0)
            result=max(sum,result)
                
        return result