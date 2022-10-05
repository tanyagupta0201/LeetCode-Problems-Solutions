# Name: Deniz Karakay
# 05/10/2022
# https://leetcode.com/problems/majority-element/

from typing import List


class Solution:
    def majorityElement(self, nums: List[int]) -> int:
        length = len(nums)

        if length == 1:
            return nums[0]

        num_dict = {}

        for num in nums:
            if num in num_dict:
                num_dict[num] += 1
                if num_dict[num] > length // 2:
                    return num
            else:
                num_dict[num] = 1

    def majorityElementAlternative(self, nums: List[int]) -> int:
        num_dict = {}

        for num in nums:
            num_dict[num] = (num_dict.get(num) or 0) + 1

        for n in num_dict:
            if num_dict[n] > len(nums) / 2:
                return n


s = Solution()
print(s.majorityElementAlternative([2, 2, 1, 1, 1, 2, 2]))
