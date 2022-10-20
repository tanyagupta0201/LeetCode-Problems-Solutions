// Name : Stuti Verma
// Date : 20/10/2022
		
class Solution 
{
		public:
		    bool searchMatrix(vector<vector<int>>& matrix, int target) 
		    {
				    // m = total rows
				    // n = total columns
		        int m = matrix.size();
		        int n = matrix[0].size();
				    // Start from top-right corner 
		        int row = 0, col = n-1;
			    	// Traverse the matrix
		        while(row < m && col >= 0)
		        {
				   	// If target found
		            if(matrix[row][col] == target)
		                return true;
				  	// If target is smaller than current element - decrement col 
		            if(matrix[row][col] > target)
		                col--;
				  	// If target is greater than current element - increment row
		            else
		                row++;
		        }
				    // Target not found
		        return false;
		    }
};	
// Time: O(n) - in the case we have just one row		
// Space: O(1) - nothing stored
