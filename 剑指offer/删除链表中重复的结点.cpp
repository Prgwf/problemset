/*
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) :
        val(x), next(NULL) {
    }
};
*/
class Solution {
public:
  ListNode* deleteDuplication(ListNode* pHead) {
    if (pHead == nullptr) return nullptr;

    ListNode *pPrev = nullptr;
    ListNode *pNode = pHead;

    while (pNode != nullptr) {
      bool flag = 0;
      ListNode *pNext = pNode->next;
      if (pNext != nullptr and pNode->val == pNext->val) {
        flag = 1;
      }
      if (!flag) {
        pPrev = pNode;
        pNode = pNode->next;
      } else {
        int val = pNode->val;
        ListNode *pDel = pNode;
        while (pDel != nullptr and pDel->val == val) {
          pNext = pDel->next;

          delete pDel;
          pDel = nullptr;

          pDel = pNext;
        }
        if (pPrev == nullptr) {
          pHead = pNext;
        } else {
          pPrev->next = pNext;
        }
        pNode = pNext;
      }
    }

    return pHead;
  }
};
