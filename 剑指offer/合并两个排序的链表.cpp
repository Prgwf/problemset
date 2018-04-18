class Solution {
public:
    ListNode* Merge(ListNode* pHead1, ListNode* pHead2)
    {
      if (pHead1 == nullptr) return pHead2;
      if (pHead2 == nullptr) return pHead1;

      ListNode *pNode = new ListNode(min(pHead1->val, pHead2->val));
      (pHead1->val < pHead2->val) ? pHead1 = pHead1->next : pHead2 = pHead2->next;
      ListNode *pHead = pNode;

      while (pHead1 != nullptr && pHead2 != nullptr) {
        pNode->next = new ListNode(min(pHead1->val, pHead2->val));
        (pHead1->val < pHead2->val) ? pHead1 = pHead1->next : pHead2 = pHead2->next;
        pNode = pNode->next;
      }

      while (pHead1 != nullptr) {
        pNode->next = new ListNode(pHead1->val);
        pNode = pNode->next;
        pHead1 = pHead1->next;
      }

      while (pHead2 != nullptr) {
        pNode->next = new ListNode(pHead2->val);
        pNode = pNode->next;
        pHead2 = pHead2->next;
      }
      return pHead;
    }
};

class Solution2 {
public:
    ListNode* Merge(ListNode* pHead1, ListNode* pHead2)
    {
      if (pHead1 == nullptr) return pHead2;
      if (pHead2 == nullptr) return pHead1;

      ListNode *pHead = nullptr;
      if (pHead1->val < pHead2->val) {
        pHead = pHead1;
        pHead->next = Merge(pHead1->next, pHead2);
      } else {
        pHead = pHead2;
        pHead->next = Merge(pHead1, pHead2->next);
      }
      return pHead;
    }
};
