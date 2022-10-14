#Author: Poonam Parate
#Date: 13/10/22
#solution function will check the combination of letter of phone number
class Solution:
    def letterCombinations(self, digits: str) -> List[str]:
        if len(digits) == 0:
            return []
 #set a letter as present in phone number dial pad
        letters = {
            "2": "abc",
            "3": "def",
            "4": "ghi",
            "5": "jkl",
            "6": "mno",
            "7": "pqrs",
            "8": "tuv",
            "9": "wxyz",
        }
 #using backtrack we will first check 1st digit & combination with second digit letter on phone number 
        def backtrack(index, path):
            if len(path) == len(digits):
                combinations.append("".join(path))
                return
 
            possible_letters = letters[digits[index]]
            for letter in possible_letters:
 
                path.append(letter)
 
                backtrack(index + 1, path)
 
                path.pop()
 
        combinations = []
        backtrack(0, [])
        return combinations
