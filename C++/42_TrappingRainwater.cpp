// Name: Sourajyoti Bhowmik
// Date: 22/10/2022

/*
Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it can trap after raining.

Example 1:
Input: height = [0,1,0,2,1,0,1,3,2,1,2,1]
Output: 6
Explanation: The above elevation map (black section) is represented by array [0,1,0,2,1,0,1,3,2,1,2,1]. In this case, 6 units of rain water (blue section) are being trapped.

Example 2:

Input: height = [4,2,0,3,2,5]
Output: 9
*/

// https://leetcode.com/problems/trapping-rain-water/


class Solution {
public:
int trap(vector<int>& h) {
      int n=h.size();
    vector<int>ml,mr(n,0);int res=0;
 
    int mini=h[0];
    int maxi=h[n-1];
    for(int i=0;i<n;i++){
        if(h[i]>mini){
            mini=h[i];
        }
          ml.push_back(mini); //put the maximum elements till that index
    }
    for(int i=n-1;i>=0;i--){
        if(h[i]>maxi){
            maxi=h[i];
        }
      mr[i]=maxi;//put maximum element till that index
    }
    for(int i=0;i<n;i++){
        res+=(min(ml[i],mr[i])-h[i]);//take minimum of both array at the particular index and subtract the current element of the original array . this will give the amount of water which is above the particular height
    }
    return res;     
}
};
