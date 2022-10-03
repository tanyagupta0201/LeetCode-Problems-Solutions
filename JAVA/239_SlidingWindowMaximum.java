// Name: Aneesh Gupta
// Date: 3/10/2022

/*Problem
239. Sliding Window Maximum (LEETCODE)
You are given an array of integers nums, there is a sliding window of size k which is moving from the very left of the array to the very right. 
You can only see the k numbers in the window. Each time the sliding window moves right by one position. Return the max sliding window.

Meaning -> For example, if we have [1,3,-1,-3,5,3,6,7] as the input array and size of window as 3, then the obtained, answer will be [3,3,5,5,6,7].
How to implement -> We'll be using Stack data structure to solve the problem.

IDEOLOGY -> First, we'll get "Next greater element to the right for each element", and then we'll use 2 pointers. One will act as starting point for 
each window, and the other will give us the greatest element in the window. */

class Solution {
  public int[] maxSlidingWindow(int[] nums, int k) {
    int[] nge = new int[nums.length]; //nge = next greater element
    Stack < Integer > st = new Stack < > (); 
    nge[nums.length - 1] = nums.length;
    st.push(nums.length - 1);

    for (int i = nums.length - 2; i >= 0; i--) { //This loop gives us the next greater element for each element using Stack
      while (st.size() > 0 && nums[st.peek()] <= nums[i]) {
        st.pop();
      }
      nge[i] = st.size() == 0 ? nums.length : st.peek();
      st.push(i);
    }

    int[] ans = new int[nums.length - k + 1]; //This array will store the result
    int j = 0;
    for (int i = 0; i <= nums.length - k; i++) {
      j = j < i ? i : j;
      while (nge[j] < i + k) {
        j = nge[j]; // j will be placed on the next greater element for each index in the window, unless j goes outside of the window
      }
      ans[i] = nums[j];
    }
    return ans;
  }
}
