/***********Note************
442. Find All Duplicates in an Array
Medium
Given an integer array nums of length n where all the integers of nums are in the range [1, n] and each integer appears once or twice, return an array of all the integers that appears twice.

You must write an algorithm that runs in O(n) time and uses only constant extra space.

 

Example 1:

Input: nums = [4,3,2,7,8,2,3,1]
Output: [2,3]
Example 2:

Input: nums = [1,1,2]
Output: [1]
Example 3:

Input: nums = [1]
Output: []
 

Constraints:

n == nums.length
1 <= n <= 105
1 <= nums[i] <= n
Each element in nums appears once or twice.
*/
class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> ans;
        sort(nums.begin(),nums.end());
        int firstElement=nums[0];
       for(int i=1;i<nums.size();i++){
           if((firstElement^nums[i])==0){
               ans.push_back(nums[i]);
           }
           firstElement=nums[i];
       }
        return ans;
    }
};