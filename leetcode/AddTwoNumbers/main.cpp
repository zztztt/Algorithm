/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
  public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
      ListNode *r = new ListNode(0);
      ListNode *rit = r;

      int temp = 0;
      int n1, n2, val;
      while(l1 != NULL || l2 != NULL || temp != 0) {
        if (l1 != NULL) {
          n1 = l1->val;
          l1 = l1->next;
        } else {
          n1 = 0;
        }
        if (l2 != NULL) {
          n2 = l2->val;
          l2 = l2->next;
        } else {
          n2 = 0;
        }
        val = (n1 + n2 + temp) % 10;
        temp = (n1 + n2 + temp) / 10;
        rit->next = new ListNode(val);
        rit = rit->next;
      }
      return r->next;
    }
};
