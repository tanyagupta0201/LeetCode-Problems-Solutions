# Name: Deniz Karakay
# 05/10/2022
# https://leetcode.com/problems/group-anagrams/

from typing import List


class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        str_dict = {}
        for ind, str in enumerate(strs):
            sorted_str = "".join(sorted(str))

            if sorted_str in str_dict:
                str_dict[sorted_str] += [ind]

            else:
                str_dict[sorted_str] = [ind]

        output = []
        for indexes in str_dict.values():
            temp = []
            for index in indexes:
                temp.append(strs[index])
            output.append(temp)

        return output

s = Solution()
print(s.groupAnagrams(["eat", "tea", "tan", "ate", "nat", "bat"]))
