# Author: Atharv Patil
# Date: 18.10.22

class Solution:
    def breakPalindrome(self, a: str) -> str:
        if len(a) == 1:
            return ""
        i = 0
        j = len(a)-1
        while i < j:
            if a[i] != "a":
                return a[:i]+"a"+a[i+1:]
            i += 1
            j -= 1
        return a[:-1]+"b"
