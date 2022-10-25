// Name: Akshat Srivastava
// Date: 25-10-2022

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
      // creating map to store all the values
        map<int, int> mp;
      // iterationg over rhe vector
        for(int i = 0; i < nums.size(); i++){
          // if map already contain the value that means duplicate element present
            if((mp.find(nums[i]) != mp.end()) && i - mp[nums[i]] <= k) 
              return true;
            mp[nums[i]] = i;
        }
        return false;
    }
};
