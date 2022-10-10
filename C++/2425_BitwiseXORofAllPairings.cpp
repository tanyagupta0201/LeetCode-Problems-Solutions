
   // Name:  G Nitesh Kuamr Reddy
   // Date:  10/10/2022

/*
You are given two 0-indexed arrays, nums1 and nums2, consisting of non-negative integers. There exists another array, nums3, which contains the bitwise XOR of all pairings of integers between nums1 and nums2 (every integer in nums1 is paired with every integer in nums2 exactly once).

Return the bitwise XOR of all integers in nums3.

nums1 = [2,1,3], nums2 = [10,2,5,0]
Output: 13

*/

/*

Approach
There are four case

// case1
case 1:both the array nums1 and nums2 have even length
xor of all pair will cancel each other
let's take example

intput:
nums1:[1,2] nums2[3,4]
output:
1^3, 1^4
2^3 ,2^4

all the elements of the nums1 exit even number of times in the result array so that they will cancel each othere

// case 2
case 2:both the  array nums1 and nums2 have odd length
if both array have odd length then then result array will be xor of all elements of the both the array
input:
[1,2,3] [4,5,6]
1^4 1^5 1^6
2^4 2^5 2^6
3^4 3^5 3^6

 ans =1^2^3^4^5^6


// case 3
case 3:nums1 have odd length and nums2 have even length
input [1,2,3] [5,4]
1^5 1^4
2^5 2^4
3^5 3^4

all the elements of the array nums1 will cancel each other
ans=5^4

// case 4
case 4:nums1 have even length and nums1 have odd length
input:[4,5] [3,8,1]
4^3 4^8 4^1
5^3 5^8 5^1

all the elements of the nums2 will cancel each other
ans=4^5


*/

class solution
{
public:
    int xorAllNums(vector<int> &nums1, vector<int> &nums2)
    {
        int ans = 0;
        int n = nums1.size();
        int n1 = nums2.size();
        if (n % 2 == 0 and n1 % 2 == 0)
            return 0;         // both the array have even len
        if (n & 1 and n1 & 1) // both the array have odd len
        {
            for (auto it : nums1)
                ans = ans ^ it; // xor of all elements of the nums1
            for (auto it : nums2)
                ans = ans ^ it; // xor of all elements of the nums2
        }
        else if (n & 1 and n1 % 2 == 0)
            for (auto it : nums2)
                ans = ans ^ it; // nums1 have odd len while nums2 have even len
        else if (n % 2 == 0 and n1 & 1)
            for (auto it : nums1)
                ans = ans ^ it; // nums2 have even len while nums1 have odd len
        return ans;
    }
};
