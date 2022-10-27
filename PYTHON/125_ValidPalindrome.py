# Name - Esan  Raj
# Date -22/10/2022


class Solution:
    def isPalindrome(self, s: str) -> bool:
        a = ""
        for x in [*s]:
            if (
                x.isalpha()
            ):  # comparing x in given string that ,it is a character or not
                a += (
                    x.lower()
                )  # converting the text to lower case and then add the character to string 'a'
            if x.isnumeric():  # comparing x in given string that, it is a number or not
                a += x  # adding the character in the string 'a'
        return (
            a == a[::-1]
        )  # comparing the string with itself by traversing it in reverse order for palindrome.