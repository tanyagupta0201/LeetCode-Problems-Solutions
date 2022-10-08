
/*

ayushi singh 
date-8/10/22

problem statement-
Given an integer n, return true if it is a power of two. Otherwise, return false.
An integer n is a power of two, if there exists an integer x such that n == 2^x.

Test cases-
Input: n = 1
Output: true
Explanation: 20 = 1

Input: n = 16
Output: true
Explanation: 24 = 16

Input: n = 3
Output: false
 

Constraints:
-231 <= n <= 231 - 1

  
Time Submitted
Status
Runtime
Memory
Language
10/08/2022 11:32	Accepted	0 ms	5.7 MB	cpp


 */
class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n==1)
            return true;
        
        else if(n%2!=0||n==0)
            return false;
        
        return isPowerOfTwo(n/2);
    }
};