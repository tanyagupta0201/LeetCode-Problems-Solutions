//TC : O(nlogn)
//SC : O(1)
class Solution {
    public int threeSumClosest(int[] arr, int target) {
      //sort the array
        Arrays.sort(arr);
        int n = arr.length;
      //assign with 0, by default
        int ans = 0;
      //assign with maximum value, because we need the minimum difference
        int diff = Integer.MAX_VALUE;
        for(int i=0; i<n; i++) {
          //using two-pointer approach
            int start = i+1, end = n-1;
            while(start<end) {
              //getting the sum of three element
                int sum = arr[i]+arr[start]+arr[end];
              //checking the sum equal to target, then directly return from here
              if(sum==target) return target;
              //if the absolute difference of target-sum is less than diff
              //that means, we have found a new closest sum, so assign the ans with new sum & change the diff variable 
                if(Math.abs(target-sum)<diff) {
                    diff = Math.abs(target-sum);
                    ans = sum;
                }
              // if sum is less than target, then we need to increament the sum, that's why increament the start
              //or else if sum is greater the target, then decreament the end
                if(sum<target) start++;
                else end--;
            }
        }
      //at the end return the ans
        return ans;
    }
}
