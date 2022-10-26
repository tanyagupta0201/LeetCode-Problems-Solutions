// Name: Aditya Byju
// Date: 26/10/2022

/*
    Given two strings needle and haystack, return the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.

    Eg:
        Input: haystack = "sadbutsad", needle = "sad"
        Output: 0
        Explanation: "sad" occurs at index 0 and 6. The first occurrence is at index 0, so we return 0.

    Time complexity: O(m+n)
    (m is length of haystack and n is length of needle)
    Space complexity: O(1)
*/

class Solution
{
public:
    int strStr(string haystack, string needle)
    {
        int m = haystack.size(), n = needle.size();

        // if length of haystack is less than that of needle then needle can't occur in haystack, so return -1
        if (m < n)
            return -1;

        // loop to search for occurence of needle in haystack
        for (int i = 0; i < m - n + 1; ++i)
        {
            // here we are just comparing the first element of needle with each element of haystack for efficiency
            if (haystack[i] == needle[0])
            {
                // if the first element of needle matches with an element of haystack, then check if the succeeding substring of length n in haystack is needle
                if (haystack.substr(i, n) == needle)
                {
                    return i;
                }
            }
        }

        // if needle is not found in haystack return -1
        return -1;
    }
};