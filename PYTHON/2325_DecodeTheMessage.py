# Name: Ira 
# Date: 02/10/2022

class Solution:
    def decodeMessage(self, key: str, message: str) -> str:
        k = ""
        for i in key:
            if i not in k and i != " ":
                k += i
        key = k
        ref = {}
        j = 97
        for i in range(len(key)):
            ref[key[i]] = chr(j)
            # print(chr(j))
            j += 1
        # print(ref)
        res = ''
        for i in message:
            if i != " ":
                res += ref[i]
            else:
                res += " "
        return res
                