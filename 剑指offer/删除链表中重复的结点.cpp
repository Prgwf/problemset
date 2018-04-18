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

    }

    return pHead;
  }
};
