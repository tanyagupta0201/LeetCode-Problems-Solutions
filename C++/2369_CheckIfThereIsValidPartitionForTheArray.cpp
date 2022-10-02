/*
Name : Vipin Kumar
Date : 2nd October 2022
*/

// Link to proper explanation
// https://leetcode.com/problems/check-if-there-is-a-valid-partition-for-the-array/discuss/2405370/c-simple-intuitive-memoization

class Solution {
public:
	
    // checking for cond1 if two adjacent elements are equal
    bool cond1(int idx, vector<int> &nums){
        return idx >= 1 && (nums[idx] == nums[idx - 1]);
    }
	
    // checking for cond2 if three adjacent elements are equal
    bool cond2(int idx, vector<int> &nums){
        return idx >= 2 && (nums[idx] == nums[idx - 1] && nums[idx - 1] == nums[idx - 2]);
    }
    
    // checking for cond3 if three adjacent elements are consecutive increasing
    bool cond3(int idx, vector<int> &nums){
        return idx >= 2 && ((nums[idx] - nums[idx - 1]) == 1) && ((nums[idx - 1] - nums[idx - 2]) == 1);
    }
    
    bool check(int idx, vector<int> &nums, vector<int> &dp){
        
	// base condition have reached to -1 index than it is possible to partition
        if((idx + 1) == 0) return true;
        
	// if we have already find answer of present index just return it
        if(dp[idx] != -1) return dp[idx];
		
	// this tells whether it is possible to partition or not
        bool ok = false;
        
	// check for all three conditions if any of them returns true ok will be true
        if(cond1(idx, nums)) ok |= check(idx - 2, nums, dp);
        if(cond2(idx, nums)) ok |= check(idx - 3, nums, dp);
        if(cond3(idx, nums)) ok |= check(idx - 3, nums, dp);
        
	// memoization step we are storing answer of present index so that we do not calculate again
        return dp[idx] = ok;
    }
    
    bool validPartition(vector<int>& nums) {
        
        int n = nums.size();
        
	// dp array is initialised by -1 which denotes answer is not obtained by any of indexes
        vector<int> dp(n + 1, -1);
		
	// we are checking from the end of array 
        return check(n - 1, nums, dp);
    }
};
