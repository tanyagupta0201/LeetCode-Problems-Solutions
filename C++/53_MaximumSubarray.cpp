class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        
// method1 = will use nested for loops 
//         and TC will be O(N^2)
        
// method2 = will use single for loop only
//         and TC will be O(N)
        
        
         int sum=nums[0], max_sum=nums[0];
        for(int i=1; i<nums.size(); i++) 
        {
            sum = max(nums[i], sum+nums[i]);
            if(sum>max_sum) 
            {
                max_sum=sum;
            }
        }
        return max_sum;
    }
};
