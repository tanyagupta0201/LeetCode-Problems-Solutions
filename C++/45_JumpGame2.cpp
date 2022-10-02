//Name: Anikalp Jaiswal
// Date: 02/10/2022

/*Problem statment: 

You are given a 0-indexed array of integers nums of length n. You are initially positioned at nums[0].
Each element nums[i] represents the maximum length of a forward jump from index i. In other words, if you are at nums[i], you can jump to any nums[i + j] where:
1 <= j <= nums[i] and
i + j < n
Return the minimum number of jumps to reach nums[n - 1]. The test cases are generated such that you can reach nums[n - 1]*/

/* Test Case: 
Input: nums = [2,3,1,1,4]
Output: 2
Explanation: The minimum number of jumps to reach the last index is 2. Jump 1 step from index 0 to 1, then 3 steps to the last index.*/


//Runtime: 28 ms
//Memory Usage: 16.5 MB


 class Solution {
public:
    int jump(vector<int>& N) {
        int len = N.size() - 1, curr = -1, next = 0, ans = 0;
        for (int i = 0; next < len; i++) {
            if (i > curr) ans++, curr = next;
            next = max(next, N[i] + i);
        };
        return ans;
    }
};
        
