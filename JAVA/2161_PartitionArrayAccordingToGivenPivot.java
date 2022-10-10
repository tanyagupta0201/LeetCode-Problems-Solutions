// Aneesh Gupta
// 10-10-2022

class Solution {
    public int[] pivotArray(int[] nums, int pivot) {
    
        int pivotFreq = 0;
        ArrayDeque<Integer> smele = new ArrayDeque<>();
        ArrayDeque<Integer> lgele = new ArrayDeque<>();
        
        for(int val : nums){
            if(val < pivot){
                smele.add(val);
            } else if(val == pivot) {
                pivotFreq++;
            } else {
                lgele.add(val);
            }
        }
        
        for(int i = 0; i < nums.length; i++){
            if(smele.size() > 0){
                nums[i] = smele.remove();
            } else if(pivotFreq-- > 0) {
                nums[i] = pivot;
            } else {
                nums[i] = lgele.remove();
            }
        }
        return nums;
    }
}
