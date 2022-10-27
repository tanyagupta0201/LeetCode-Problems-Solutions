# Name : Simran Kukreja
# Date : 26th Oct 2022

class Solution(object):
    def arrayStringsAreEqual(self, word1, word2):
        """
        :type word1: List[str]
        :type word2: List[str]
        :rtype: bool
        """
        str1 = ""
        str2 = ""
        
        # Create a single string of all elements in array 1 
        for i in word1:
            str1 += i
            
        # similarly in array 2
        for i in word2:
            str2 += i
            
        # check if both are equal or not
        return (str1 == str2)
