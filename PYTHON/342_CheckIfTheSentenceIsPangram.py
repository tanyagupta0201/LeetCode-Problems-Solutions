# Author:Chengalva Sai Harikha
# DATE:17/10/2022

class Solution(object):
    def checkIfPangram(self, sentence):
        """
        :type sentence: str
        :rtype: bool
        """
        # array of size 26 is created with all elements 0
        array = [0] * 26
        # traversal through the sentance and update the values
        for i in sentence:
            array[ord(i) - ord("a")] = array[ord(i) - ord("a")] + 1
        return 0 not in array
