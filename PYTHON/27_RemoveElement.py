# Name - Akruti Sarangi
# Date - 20/10/2022
# According to the problem we have to remove element from the list and return the count of elements after removing that element
class Solution(object):
    """
        :type nums: List[int]
        :type val: int
        :return output type: int
    """
    def removeElement(self, nums, val):
        ls = len(nums)
        if ls == 0:
            return ls
        count = 0
        index = 0
        # count to find the no. of elements that needs to be removed 
        while index < ls - count:
            if nums[index] == val:
                nums[index] = nums[ls - 1 - count]
                count += 1
            else:
                index += 1
        return ls - count         # returns the no. of elements present after removing the elements that needs to be removed 

if __name__ == '__main__':
    # begin
    s = Solution()
    print s.removeElement([1], 1)
