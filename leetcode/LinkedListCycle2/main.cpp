/*
 * Given a linked list, return the node where the cycle begins, if there is no cycle, return null.
 */
/*
 * Solution:
 *   fast, slox fisrt meet at step K, 2K-K=nr, r is the length of the cycle,
 *   so K = nr, if m is the distance between the start node of the cycle and the 
 *   meet node of the cycle, nr - m is the distance between the head node and the 
 *   start node of the cycle, when a node A start from head, and node B start from the
 *   meeting node, they wake one step at a time, then when A go nr - m steps, B will go 
 *   nr - m steps too. they whill meet at the start node of the cycle
 */
#include <stdio.h>

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
  public:
    ListNode* detectCycle(ListNode *head) {
      ListNode *fast = head;      
      ListNode *slow = head;
      while(fast && fast->next && fast->next->next) {
        fast = fast->next->next;
        slow = slow->next;
        if (fast == slow) {
          slow = head;
          while(fast != slow) {
            fast = fast->next;
            slow = slow->next;
          }
          return slow;
        }
      }
      return NULL;
    }
};
