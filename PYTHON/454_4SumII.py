# Name: Deniz Karakay
# 05/10/2022
# https://leetcode.com/problems/4sum-ii/

from typing import List


class Solution:
    def fourSumCount(self, nums1: List[int], nums2: List[int], nums3: List[int], nums4: List[int]) -> int:

        answers = {}

        count = 0
        for a in nums1:
            for b in nums2:
                sum_first = a + b
                if sum_first in answers:
                    answers[sum_first] += 1
                else:
                    answers[sum_first] = 1

        for c in nums3:
            for d in nums4:
                target = -1 * (c + d)

                if target in answers:
                    count += answers[target]

        return count


s = Solution()
print(s.fourSumCount(nums1=[1, 2], nums2=[-2, -1], nums3=[-1, 2], nums4=[0, 2]))
