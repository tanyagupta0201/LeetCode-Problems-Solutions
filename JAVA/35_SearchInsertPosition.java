// Name: Ritika Rastogi
// Date: 29-10-2022
class Solution {
  public int searchInsert(int[] nums, int target) {
    int first = 0;
    int last = nums.length - 1;
    int mid = 0;
    int flag = 0;

    while (first <= last) // Traversing the array till first becomes last.
    {
      mid = (first + last) / 2; // Calculating the mid position in the array
      if (target > nums[mid])
        first = mid + 1; // Changing the first position to middle index+1 if the value of target is greater than the value of middle element.
      else if (target < nums[mid])
        last = mid - 1; // Changing the last position to middle index-1 if the value of target is less than the value of middle element.
      else {
        flag = -1;
        return mid;
      }

    }

    return first;

  }

}