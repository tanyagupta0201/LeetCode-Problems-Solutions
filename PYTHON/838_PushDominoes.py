# Name: Himanshi Garg
# Date: 06/10/2022

class Solution:
    def pushDominoes(self, dominoes: str) -> str:
        prevString = ""
        current = dominoes

        if len(dominoes) == 1:  # If there is only one domino
            return dominoes

        while prevString != current:
            prevString = current
            current = ""
            for i in range(len(dominoes)):

                if i != 0 and i != len(prevString) - 1:
                    if prevString[i] == ".":
                        if prevString[i-1] == "R" and prevString[i+1] != "L":  # "R.." or "R.R" -- in both cases it will expend force on ith domino towards right
                            current += "R"                  
                        elif prevString[i+1] == "L" and prevString[i-1] != "R": # "..L" or "L.L" -- in both cases it will expend force on ith domino towards left
                            current += "L"                  
                        else:
                            current += "."                  # neither right nor left
                    else:
                        current += prevString[i]
                elif i == 0:
                    if prevString[0] == "." and prevString[i+1] == "L": # ".L" -- resultant force will be towards left
                        current += "L"
                    else:  
                        current += prevString[0]

                elif i == len(prevString)-1:   
                    if prevString[i] == "." and prevString[i-1] == "R":  # "R." -- resultant force will be towards right
                        current += "R"
                    else:
                        current += prevString[i]

        return current
