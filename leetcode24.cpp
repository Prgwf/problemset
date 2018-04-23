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
  ListNode* swapPairs(ListNode* head) {
    ListNode **p = &head, *a, *b;

    while ((a = *p) && (b = a->next)) {
      a->next = b->next;
      b->next = a;
      *p = b;
      p = &(a->next);
    }
    
    return head;
  }
};
