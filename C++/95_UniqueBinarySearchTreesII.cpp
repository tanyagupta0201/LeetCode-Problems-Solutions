// Name: Harshit Jain
// Date: 20/10/2022

/*
Given an integer n, return all the structurally unique BST's (binary search trees), which has exactly n nodes of unique values from 1 to n.
Return the answer in any order.

https://leetcode.com/problems/unique-binary-search-trees-ii/

*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
  public:

    vector < TreeNode * > solve(int start, int end) {
      vector < TreeNode * > res;
      
      if (start > end)
        return {
          NULL
        };
      
      if (start == end)
        return {
          new TreeNode(start)
        };

      for (int i = start; i <= end; i++) {
        // first find left and right binary search tree
        vector < TreeNode * > left = solve(start, i - 1), right = solve(i + 1, end);

        // find all the answer by multplying left and right tree
        for (auto l: left) {
          for (auto r: right) {
            res.push_back({
              new TreeNode(i, l, r)
            });
          }
        }
      }
      return res;
    }
  
  vector < TreeNode * > generateTrees(int n) {
    vector < TreeNode * > res = solve(1, n);
    return res;
  }
};
