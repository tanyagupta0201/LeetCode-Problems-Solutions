/*
Name :  Amit Maity
Date :  02.10.2022
*/


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
	//Create child-parent combination in a Map such that we can track easily
    void markParents(TreeNode* root, unordered_map<TreeNode*, TreeNode*> &parent_track) {
    	//make a queue for BFS Traversal
        queue<TreeNode*> queue;
        //add the root at first
        queue.push(root);
        while(!queue.empty()) { 
            //First Node Pull
            TreeNode* current = queue.front(); 
            queue.pop();
            //if left node exist then add child-parent combination in Map
            if(current->left) {
                parent_track[current->left] = current;
                queue.push(current->left);
            }
            //if Right node exist then add child-parent combination in Map
            if(current->right) {
                parent_track[current->right] = current;
                queue.push(current->right);
            }
        }
    }
    //This is the Given function
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
    	//Craete a Map for track all the child-parent combinations
        unordered_map<TreeNode*, TreeNode*> parent_track; 
        //call this function for creating child-parent combination
        markParents(root, parent_track); 
        
        //Create this map for tracking all the visited node
        unordered_map<TreeNode*, bool> visited; 
        queue<TreeNode*> queue;
        queue.push(target);
        //mark as visited
        visited[target] = true;
        int curr_level = 0;
        while(!queue.empty()) { 
            int size = queue.size();
            //whenever curr_level == k then break
            if(curr_level++ == k) break;
            for(int i=0; i<size; i++) {
                TreeNode* current = queue.front(); queue.pop();
                //if left node exist && not visited then visit and mark as visited
                if(current->left && !visited[current->left]) {
                    queue.push(current->left);
                    visited[current->left] = true;
                }
                //if right node exist && not visited then visit and mark as visited
                if(current->right && !visited[current->right]) {
                    queue.push(current->right);
                    visited[current->right] = true;
                }
                //reverse back check 
                if(parent_track[current] && !visited[parent_track[current]]) {
                    queue.push(parent_track[current]);
                    visited[parent_track[current]] = true;
                }
            }
        }
        //create a vector
        vector<int> result;
        while(!queue.empty()) {
            TreeNode* current = queue.front(); queue.pop();
            //add the remaining elements in the queue
            result.push_back(current->val);
        }
        return result;
    }
    
};
