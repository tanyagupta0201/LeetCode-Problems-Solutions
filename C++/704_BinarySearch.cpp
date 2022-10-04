// Name: Shubham Yadav 
// Date: 4/10/22

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size()-1;
        int s = 0, e = n;
        
        while(s<=e){
            int m = s + (e-s)/2;
            
            if(nums[m]==target) return m;
            
            else if(nums[m]>target) e = m-1;
            
            else s = m+1;
        }
        
        return -1;
    }
};