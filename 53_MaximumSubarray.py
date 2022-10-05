class Solution:
    def maxSubArray(self, nums: List[int]) -> int:  #function to calculate maximum sum
        result = max(nums)  #store the maximum value in nums in result variabe
        if result<=0:
            return result
        
        sum = 0
        for i in nums:
            sum = max(sum+i,0)    #update value of sum in each iteration by adding each value in nums
            result=max(sum,result)  #find the maximum value from updated sum and result and store in result
                
        return result
