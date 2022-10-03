// Name: Souvik Pal
// Date: 03/10/2022

/*
Problem Statement :
1578. Minimum Time to Make Rope Colorful (LEETCODE)

Alice has n balloons arranged on a rope. You are given a 0-indexed string colors where colors[i] is the color of the ith balloon.

Alice wants the rope to be colorful. She does not want two consecutive balloons to be of the same color, so she asks Bob for help. Bob can remove some balloons from the rope to make it colorful. You are given a 0-indexed integer array neededTime where neededTime[i] is the time (in seconds) that Bob needs to remove the ith balloon from the rope.

Return the minimum time Bob needs to make the rope colorful.

Example 1:
Input: colors = "abaac", neededTime = [1,2,3,4,5]
Output: 3
Explanation: In the above image, 'a' is blue, 'b' is red, and 'c' is green.
Bob can remove the blue balloon at index 2. This takes 3 seconds.
There are no longer two consecutive balloons of the same color. Total time = 3.

Example 2:
Input: colors = "abc", neededTime = [1,2,3]
Output: 0
Explanation: The rope is already colorful. Bob does not need to remove any balloons from the rope.

Example 3:
Input: colors = "aabaa", neededTime = [1,2,3,4,1]
Output: 2
Explanation: Bob will remove the ballons at indices 0 and 4. Each ballon takes 1 second to remove.
There are no longer two consecutive balloons of the same color. Total time = 1 + 1 = 2.
*/

class Solution {
    public int minCost(String colors, int[] neededTime) {
        int length = colors.length();

        int p1 = 0;
        int p2 = 1;
        int totalTime = 0;
        
        while(p2 != length){
            char ballon = colors.charAt(p1);
            char nextBallon = colors.charAt(p2);
            if(ballon == nextBallon){
                if(neededTime[p1] < neededTime[p2]){
                    totalTime = totalTime + neededTime[p1];
                    p1 = p2;
                    p2++;
                }else{
                    totalTime = totalTime + neededTime[p2];
                    p2++;
                }
            }else{
                p1 = p2;
                p2++;
            }
        }
        
        return totalTime;
    }
}