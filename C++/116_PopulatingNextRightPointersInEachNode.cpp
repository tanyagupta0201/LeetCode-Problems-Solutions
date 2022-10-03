// Name : Karthik S
// Date : 03 October 2022

class Solution {
  public:
    Node * connect(Node * root) {
      queue < Node * > q;
      Node * root1 = root;
      if (root1 == NULL)
        return NULL;

      q.push(root1);

      while (!q.empty()) {
        int n = q.size();
        Node * prev = NULL;
        for (int i = 0; i < n; i++) {
          Node * curr = q.front();
          q.pop();

          if (curr -> left != NULL)
            q.push(curr -> left);
          if (curr -> right != NULL)
            q.push(curr -> right);

          if (prev == NULL) {
            prev = curr;
            prev -> next = NULL;
            continue;
          }

          prev -> next = curr;
          prev = curr;
          if (i == n - 1)
            curr -> next = NULL;
        }
      }
      return root;
    }
};
