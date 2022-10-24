// Name: Ayush Sharma
// Date: 24/10/2022

/*
Problem Statement :
35. Search Insert Position (LEETCODE - Easy)
Given a sorted array of distinct integers and a target value, return the index if the target is found. If not, return
the index where it would be if it were inserted in order.
You must write an algorithm with O(log n) runtime complexity.

Example 1:
Input: nums = [1,3,5,6], target = 5
Output: 2

Example 2:
Input: nums = [1,3,5,6], target = 2
Output: 1

Example 3:
Input: nums = [1,3,5,6], target = 7
Output: 4

Solution Explanation :-
Since the problem statement asked us to insert the number at the valid position in array, we will simply check if the
number is present in it's valid position or not. We will use binary search algorithm to obtain the valid position and
return it.

Time Complexity - O(log N)
Space Complexity - O(1)
*/

class Solution {
    public int searchInsert(int[] nums, int target) {
        int start = 0;
        int end = nums.length - 1;
        while (start <= end) {
            int mid = start + (end - start) / 2;
            if (target < nums[mid]) {
                end = mid - 1;
            } else if (target > nums[mid]) {
                start = mid + 1;
            } else {
                return mid;
            }
        }
        return end + 1;
    }
}