/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
#include<stdio.h>
struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
  public:
    ListNode *insertionSortList(ListNode *head) {
      if (head == NULL || head->next == NULL)
        return head;
      ListNode *rhead = new ListNode(head->val);
      ListNode *p = head->next;
      while(p!= NULL) {
        ListNode *r = rhead;
        while(r->next != NULL && r->next->val <= p->val) {
          r = r->next; 
        }
        if (r == rhead && r->val > p->val) {
          rhead = new ListNode(p->val);
          rhead->next = r;
        } else {
          ListNode *new_node = new ListNode(p->val);
          new_node->next = r->next;
          r->next = new_node;
        }
        p = p->next;
      }
      return rhead;
    }
    void debug(ListNode *p) {
      while(p != NULL) {
        printf("%d\n", p->val);
        p = p->next;
      }
    }
};
int main() {
  ListNode *n1 = new ListNode(2);
  ListNode *n2 = new ListNode(1);
  n1->next = n2;
  Solution s;
  s.debug(s.insertionSortList(n1));
  return 0;
}
