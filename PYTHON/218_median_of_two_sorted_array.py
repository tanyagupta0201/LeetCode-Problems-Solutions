'''
Author Name : Shivang Saxena
Modified On : 06-10-2022
Leet code problem number : 4
Mode : Hard
'''


class Solution:
    def findMedianSortedArrays(self,nums1,nums2):
        sorted_array = nums1 + nums2
        sorted_array = sorted(sorted_array)
        print(sorted_array)
        length = len(sorted_array)
        if(length % 2 == 0):
            middle_element = int(length/2)-1
            return (sorted_array[middle_element] + sorted_array[middle_element+1]) /(2)
        else:
            middle_element = int(length/2)
            return sorted_array[middle_element]

