# Name: Ritika Rastogi
# Date: 30-10-2022
class Solution:
    def convertToTitle(self, columnNumber: int) -> str:
        rev = ""
        while columnNumber != 0:
            # First we calculate the remainder obtained by dividing with 26 as there are 26 letters.
            a = columnNumber % 26
            # If the remainder is not 0, we add the equivalent alphabet to the variable rev
            if a != 0:
                rev = rev + chr(64 + a)
                columnNumber = columnNumber // 26
            else:
                rev = rev + "Z"  # Otherwise, we add Z to the rev variable
                columnNumber = (columnNumber // 26) - 1
        s = rev[-1::-1]  # Now as the answer is stored in reverse order, we reverse the string before returning it.
        return s
