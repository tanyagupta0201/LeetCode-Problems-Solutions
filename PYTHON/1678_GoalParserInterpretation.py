# Name: Swapnanil Ray
# Date: 05/10/2022

class Solution:
    def interpret(self, command: str) -> str:
        newStr = ""
        for i in range(len(command)):
            if command[i] == "G":
                newStr = newStr + "G"
            elif command[i] == "(":
                if command[i + 1] == ")":
                    newStr = newStr + "o"
                    i = 2
                elif command[i + 1] == "a":
                    newStr = newStr + "al"
                    i = 4
        return newStr
