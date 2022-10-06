// Name : Nivesh Pai
// Date : 06/10/2022

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(begin(nums), end(nums));
        int result = 0, min_diff = numeric_limits<int>::max();
        // Use for loop to iterate until the end of n numbers
        for (int i = size(nums) - 1; i >= 2; --i) {
            if (i + 1 < size(nums) && nums[i] == nums[i + 1]) {
                continue;
            }
            int left = 0, right = i - 1; //take left node = 0 and right node = ith element -1
            // Using while, check for condition to find the closest node to the sum of three numbers
            while (left < right) {
                const auto& total = nums[left] + nums[right] + nums[i];
                if (total < target) {
                    ++left; //Here addition of left node is done
                } else if (total > target) {
                    --right; //Decrease the right node
                } else {
                    return target; //If the central number is equal to left or right, no change in target value.
                }
                if (abs(total - target) < min_diff) {
                    min_diff = abs(total - target);
                    result = total; //Calculate the total based on the closest of three sum
                }
            }
        }
        return result; //Display the final result
    }
};

// Time Complexity:  O(n^2)
// Space Complexity: O(1)
