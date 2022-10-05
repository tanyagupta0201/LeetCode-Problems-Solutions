// Name : Rishabh Arya
// Date : 05/10/2022

// You are given two 0-indexed arrays, nums1 and nums2, consisting of non-negative integers. 
// There exists another array, nums3, which contains the bitwise XOR of all pairings of integers between nums1 and nums2.
// Return the bitwise XOR of all integers in nums3.


class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();
        int x1 = 0,x2 = 0;
        for(auto a : nums1)     // XOR of nums1
            x1 = x1^a;
        
        for(auto a : nums2)     // XOR of nums2
            x2 = x2^a;
        
        // We know that the XOR of even number of elements is Zero and XOR of odd number of elements is the number itself.
        
        if(n1 % 2 == 0 && n2 % 2 == 0)
            return 0;
        else if(n1 % 2 == 0 && n2 % 2 == 1)
            return x1;
        else if(n1 % 2 == 1 && n2 % 2 == 0)
            return x2;
        else 
            return x1^x2;
    }
};
