// Name: Sourajyoti Bhowmik
// Date: 22/10/22


class Solution {
    public void nextPermutation(int[] nums) {
        
        int n = nums.length;
        if(n == 0 || n == 1) return;
        
        // start from end , find out breaking point (index1)
        int i = n-2;
        while(i>=0 && nums[i] >= nums[i+1]) i--;
        
        if(i >= 0){
            // find slightly greater element than index1 (index2)
            int j = n-1;
            while(nums[j] <= nums[i]) j--;
        
            // swap index1 and index2
            swap(nums, i,j);
        }
       
        // reverse index1+1 to end
        reverse(nums, i+1, n-1);
    }
    
    private void swap(int[] nums, int i, int j){
        
        int temp = nums[i];
        nums[i] = nums[j];
        nums[j] = temp;
    }
    
    private void reverse(int[] nums, int i, int j){
        
        while(i < j) swap(nums, i++, j--);
    }
}
