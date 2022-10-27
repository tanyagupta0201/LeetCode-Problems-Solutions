// Name: Kavindu Lakmal
// Date: 22/10/2022

/* 
Given a fixed-length integer array arr, duplicate each occurrence of zero, shifting the remaining elements to the right.

Note that elements beyond the length of the original array are not written. Do the above modifications to the input array in place and do not return anything.

Example 1:

Input: arr = [1,0,2,3,0,4,5,0]
Output: [1,0,0,2,3,0,0,4]
Explanation: After calling your function, the input array is modified to: [1,0,0,2,3,0,0,4]

Example 2:

Input: arr = [1,2,3]
Output: [1,2,3]
Explanation: After calling your function, the input array is modified to: [1,2,3]

Implementation:

We create a new List and add elements in the order of which the provided array elements appear.

Now if the ith element is zero, we add two zeroes to the new list and if not,

we add the respective ith element of the provided array.

finally, once the new list consists of elements where the size is equal to arr.length,

we can loop over that list and change the initial array elements with the new one.
*/

class Solution {
    public void duplicateZeros(int[] arr) {
        List<Integer> newList = new ArrayList<>();
        for(int i = 0; i < arr.length; i++) {
            if(arr[i] == 0) {
                newList.add(0);
                newList.add(0);
            }
             else {
                 newList.add(arr[i]);
             }
        }
        for(int i = 0; i < arr.length; i++)
            arr[i] = newList.get(i);
    }
}