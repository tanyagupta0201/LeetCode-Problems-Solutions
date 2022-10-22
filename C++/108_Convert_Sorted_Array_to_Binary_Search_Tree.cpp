#include <iostream>
#include <bits/stdc++.h>
#include <cmath>

using namespace std;

class Solution
{
public:
    TreeNode *sortedArrayToBST(vector<int> &nums)
    {
        return helper(nums, 0, nums.size() - 1);
    }

    TreeNode *helper(vector<int> &nums, int left, int right)
    {

        // base case
        // If the left pointer crosses right return null;
        if (left > right)
        {
            return NULL;
        }

        // as middle of the array will be the root node
        int mid = (left + right) / 2;
        TreeNode *temp = new TreeNode(nums[mid]);

        // left part from middle will be left subtree
        temp->left = helper(nums, left, mid - 1);

        // right part of array will be right subtree
        temp->right = helper(nums, mid + 1, right);
        return temp;
    }
};