// Name: Tanya Gupta
// Date: 02/10/2022

class Solution {
    public int[] twoSum(int[] nums, int target) {
        return onePass(nums, target);
    }

    public int[] onePass(int[] nums, int target) {
        Map<Integer, Integer> map = new HashMap<>();
        for (int i = 0; i < nums.length; i++) {
            // one pass prevents the use of the same index twice
            if (map.containsKey(target - nums[i])) {
                return new int[] { i, map.get(target - nums[i]) };
            }
            map.put(nums[i], i);
        }

        return null;
    }

    public int[] twoPasses(int[] nums, int target) {
        // x + y = target
        // y = target -x
        Map<Integer, Integer> map = new HashMap<>();
        for (int i = 0; i < nums.length; i++) {
            map.put(nums[i], i);
        }

        for (int i = 0; i < nums.length; i++) {
            // when 2*nums[i] == target, we may use the ith nums twice
            // unless we check map.get(target-nums[i]) != i
            if (map.containsKey(target - nums[i]) && map.get(target - nums[i]) != i) {
                return new int[] { i, map.get(target - nums[i]) };
            }
        }

        return null;
    }
}