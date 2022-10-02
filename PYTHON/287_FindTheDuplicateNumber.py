# Name: Ira
# Date: 02/10/2022

from collections import Counter
from typing import List


class Solution:
    def findDuplicate(self, nums: List[int]) -> int:
        temp = Counter(nums)
        for i in temp:
            if temp[i] > 1:
                return i