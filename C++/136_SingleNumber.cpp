// Name: Shradha Verma
// Date: 22 October 2022

// Used Bitwise XOR Operator 
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int result = 0;

        for(int i = 0; i < nums.size(); i++){   // Traverse through the vector and find the XOR of all the elements

            result ^= nums[i];      // Every element that appears twice will give XOR as zero.

        }
        return result;      // XOR of Zero and the element occuring once will result in that particular elemnet.
    }
};