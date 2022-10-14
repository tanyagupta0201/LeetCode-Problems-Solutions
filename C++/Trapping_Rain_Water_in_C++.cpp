/*

Intuition: Precomputation:
-> We can precompute the maximum height of the bar to the left and right of each bar in linear time.

Approach:

-> We will now precompute the maximum height of the bar to the left and right of the current bar.
-> Store the maximum height of the bar to the left and right of the current bar in two arrays.
-> Then iterate over the array and calculate the amount of water that can be stored in the current bar.
-> Finally add the amount of water that can be stored in the current bar to the total amount of water that can be stored in the array and return the total amount of water that can be stored in the array.

*/
// Name - Shivesh Kumar
// Date - 14/10/2022

class Solution {
public:
    int trap(vector<int>& height) {
			int n = height.size();
			if(n == 0) {
				return 0;
			}
			int left[n];
			int right[n];
			left[0] = height[0];
			for(int i = 1; i < n; i++) {
				left[i] = max(left[i - 1], height[i]);
			}
			right[n - 1] = height[n - 1];
			for(int i = n - 2; i >= 0; i--) {
				right[i] = max(right[i + 1], height[i]);
			}
			int total = 0;
			for(int i = 0; i < n; i++) {
				total += min(left[i], right[i]) - height[i];
			}
			return total;
	}
};

/*
Time Complexity: O(n), where n is the number of bars in the histogram.
Space Complexity: O(n)

*/
