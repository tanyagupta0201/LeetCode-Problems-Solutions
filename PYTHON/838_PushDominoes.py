# Name: Himanshi Garg
# Date: 06/10/2022

class Solution:
    def pushDominoes(self, dominoes: str) -> str:
        prevString = ""
        current = dominoes

        if len(dominoes) == 1:
            return dominoes

        while prevString != current:
            prevString = current
            current = ""
            for i in range(len(dominoes)):

                if i != 0 and i != len(prevString) - 1:
                    if prevString[i] == ".":
                        if prevString[i-1] == "R" and prevString[i+1] != "L":
                            current += "R"
                        elif prevString[i+1] == "L" and prevString[i-1] != "R":
                            current += "L"
                        else:
                            current += "."
                    else:
                        current += prevString[i]
                elif i == 0:
                    if prevString[0] == "." and prevString[i+1] == "L":
                        current += "L"
                    else:
                        current += prevString[0]

                elif i == len(prevString)-1:
                    if prevString[i] == "." and prevString[i-1] == "R":
                        current += "R"
                    else:
                        current += prevString[i]

        return current
