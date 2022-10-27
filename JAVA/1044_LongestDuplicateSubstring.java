// Name: Sahil Saxena
// Date: 21/10/2022

/*
Problem Statement :
1044. Longest Duplicate Substring (LEETCODE - HARD)

Given a string s, consider all duplicated substrings: (contiguous) substrings of s that occur 2 or more times. 
The occurrences may overlap.

Return any duplicated substring that has the longest possible length. 
If s does not have a duplicated substring, the answer is "".

Example 1:
Input: s = "banana"
Output: "ana"
Explanation: The answer is "ana", with the length of 3 because "ana" is repeated twice at index 1,3.

Example 2:
Input: s = "abcd"
Output: ""
Explanation: The answer is empty string ("") as there is no duplicate substring

Solution Explanation :-

We can solve this problem by using Rolling Hash with Binary Search

Since the length of the answer is in between 0 to the length of string minus 1, 
In the example one "banana", the answer is in between 0 to 5,

If we find k length substring is repeated then ans will always be greater than k 
else ans will always be less than k 
In this way we can reduced the search space.

Now for checking the duplicate string we can use Rolling Hash
For every k length substring calc the hash if it is previously computed then we can return true here

Time Complexity - O(NlogN)
Space Complexity - O(N)
*/

import java.util.*;

class Solution {
    
    String ans; // to store the answer
    
    public String longestDupSubstring(String s) {
        
        ans = "";
        
        int n = s.length();
        int low = 1 , high = n;
        
        while(low <= high) {
            
            int mid = low + (high - low) / 2; // calc the mid
            
            if(haveDuplicateString(s,mid)) {
                
                low = mid + 1; // no need to search on left side
            }
            else {
                
                high = mid - 1; // no need to search on right side
            }
        }
        
        return ans;
    }
    
    private boolean haveDuplicateString(String s,int len) {
        
        // function returns true if we have duplicate string of length len
        Set<Long> set = new HashSet<>(); // stores the hash
        
        int n = s.length();
        
        long pr = 1; // stores the product
        long hash = 0;
        long q = 31; // prime number
        
        for(int i = n - 1 ; i >= n - len ; i--) {
            
            hash = ((hash * q) + (s.charAt(i) - 'a' + 1));
            
            if(i != n-len)
            pr = (pr * 31);
        }

        set.add(hash);
        
        for(int i = n - 1 ; i >= len  ; i--) {
            
            long exclude = ((s.charAt(i) - 'a' + 1) * pr);
            long include = (s.charAt(i - len) - 'a' + 1);
            
            hash = ((hash - exclude) * q  + include);
            
            if(set.contains(hash)) {
                
                // we have found the duplicate string
                ans = s.substring(i-len,i); // update the answer
                return true;
            }
            
            set.add(hash);
        }
        
        return false;
    }
}