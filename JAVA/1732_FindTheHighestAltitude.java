// Name: Vimu
// Date: 21/10/2022

/* 
There is a biker going on a road trip. The road trip consists of n + 1 points at different altitudes. The biker starts his trip on point 0 with altitude equal 0.

You are given an integer array gain of length n where gain[i] is the net gain in altitude between points i​​​​​​ and i + 1 for all (0 <= i < n). Return the highest altitude of a point.

Example 1:

Input: gain = [-5,1,5,0,-7]
Output: 1
Explanation: The altitudes are [0,-5,-4,1,1,-6]. The highest is 1.

Example 2:

Input: gain = [-4,-3,-2,-1,4,3,2]
Output: 0
Explanation: The altitudes are [0,-4,-7,-9,-10,-6,-3,-1]. The highest is 0.

Code Explanation:

Since the first element of the points array will be 0,

each following element will be the addition of the two previous terms of points array and gain array. That is starting at index 1, the value of points[1] will be the sum of points[1] and gain[1], and so on.

Finally, out of this array, the maximum value will be our highest altitiude.
*/

class Solution {
    public int largestAltitude(int[] gain) {
        int[] points = new int[gain.length + 1];
        points[0] = 0;
        for (int i = 1; i < points.length; i++) {
            points[i] = points[i - 1] + gain[i - 1];
        }
        return Arrays.stream(points).max().getAsInt();
    }
}