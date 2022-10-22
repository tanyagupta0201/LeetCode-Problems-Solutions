// Name: Sourajyoti Bhowmik
// Date: 22/10/2022

/*
Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it can trap after raining.

Example 1:
Input: height = [0,1,0,2,1,0,1,3,2,1,2,1]
Output: 6
Explanation: The above elevation map (black section) is represented by array [0,1,0,2,1,0,1,3,2,1,2,1]. In this case, 6 units of rain water (blue section) are being trapped.

Example 2:

Input: height = [4,2,0,3,2,5]
Output: 9
*/

// https://leetcode.com/problems/trapping-rain-water/
class Solution {
public:
    int trap(vector<int>& heights) {
        int count=0;
        int i=0,j=heights.size()-1;
        int lmax=i,rmax=j;
        
        while(i<j){
            if(heights[i] > heights[lmax]) lmax=i;
            if(heights[j] > heights[rmax]) rmax=j;
            
            if(heights[i] < heights[j]){
                count+=max(0,min(heights[lmax],heights[rmax])-heights[i]);
                i++;
            }
            else{
                count+=max(0,min(heights[lmax],heights[rmax])-heights[j]);
                j--;
            }
        }
        
        return count;
    }
};
