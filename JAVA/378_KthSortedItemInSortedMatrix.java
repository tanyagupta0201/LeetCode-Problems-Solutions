// Name: Chamod Nugekotuwa
// Date: 14/10/2022

/* 
Problem Statement:

Given an n x n matrix where each of the rows and columns is sorted in ascending order, return the kth smallest element in the matrix.

Note that it is the kth smallest element in the sorted order, not the kth distinct element.

Example 1:

Input: matrix = [[1,5,9],[10,11,13],[12,13,15]], k = 8
Output: 13
Explanation: The elements in the matrix are [1,5,9,10,11,12,13,13,15], and the 8th smallest number is 13

Example 2:

Input: matrix = [[-5]], k = 1
Output: -5
*/

class Solution {
    public int kthSmallest(int[][] matrix, int k) {
        int n = matrix.length;
        // Using the smallest element as our lower boundary and largest element as the
        // upper boundary, we can progressively narrow down our search for the element
        // in mid position.
        int lowerBoundary = matrix[0][0];
        int upperBoundary = matrix[n - 1][n - 1];
        int mid;

        while (lowerBoundary <= upperBoundary) {
            // The mid element is used to determine how many elements are smaller or equal
            // to it.
            mid = lowerBoundary + (upperBoundary - lowerBoundary) / 2;
            // The count is used to narrow our search for step i. When the count is less
            // than k (our desired element at Kth position), we need to increase our lower
            // boundary, otherwise we decrease the upper boundary.
            int count = getCountLessOrEqual(matrix, mid, n);
            if (count < k)
                lowerBoundary = mid + 1;
            else
                upperBoundary = mid - 1;
        }
        return lowerBoundary;
    }

    private int getCountLessOrEqual(int[][] matrix, int val, int n) {
        int i = 0, j = n - 1;
        int res = 0;
        while (i < n) {
            while (j >= 0 && matrix[i][j] > val)
                j--;
            res += j + 1;
            i++;
        }
        return res;
    }
}