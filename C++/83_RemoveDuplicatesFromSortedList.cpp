/*
Author: Tasmiya Khan
Date: 2 October 2022
*/

class Solution {
  public:
    ListNode * deleteDuplicates(ListNode * head) {
      ListNode * ptr = head;
      if (head == nullptr) {
        return nullptr;
      }
      while (ptr -> next != nullptr) {
        if (ptr -> val == ptr -> next -> val) {
          ptr -> next = ptr -> next -> next;
        } else {
          ptr = ptr -> next;
        }
      }
      return head;
    }
};


// Another Implementation :



// Node *uniqueSortedList(Node *head)
// {

//     //  case 1: if list is empty
//     if (head == NULL)
//         return NULL;

//     // case 2 : if the given list is non - empty

//     Node *curr = head;

//     while (curr != NULL)
//     {

//         if ((curr->next != NULL) && curr->data == curr->next->data)
//         {
//             Node *next_next = curr->next->next;
//             Node *nodeToDelete = curr->next;
//             delete (nodeToDelete);
//             curr->next = next_next;
//         }
//         else
//         {
//             curr = curr->next;
//         }
//     }

//     return head;
// }
