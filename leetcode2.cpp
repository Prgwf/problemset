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
  ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    ListNode pHead(0), *pNode = &pHead;
    int sum = 0;

    while (l1 || l2 || sum) {
      if (l1) {
        sum += l1->val;  
        l1 = l1->next;
      }
      if (l2) {
        sum += l2->val;  
        l2 = l2->next;
      }
      pNode->next = new ListNode(sum % 10);
      sum /= 10;
      pNode = pNode->next;
    }
    return pHead.next;
  }
};