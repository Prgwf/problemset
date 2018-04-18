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
  ListNode *MeetingNode(ListNode *pHead) {
    if (pHead == nullptr) return nullptr;

    ListNode *pSlow, *pFast;
    pSlow = pHead;
    pFast = pHead->next;
    while (pSlow != nullptr and pFast != nullptr) {
      if (pSlow == pFast) {
        return pFast;
      }
      pSlow = pSlow->next;
      pFast = pFast->next;
      if (pFast != nullptr) {
        pFast = pFast->next;
      }
    }
    return nullptr;
  }

  ListNode* EntryNodeOfLoop(ListNode* pHead) {
    ListNode *pMeet = MeetingNode(pHead);
    if (pMeet == nullptr) return nullptr;

    int cnt = 1;
    ListNode *pNode = pMeet;
    while (pNode->next != pMeet) {
      pNode = pNode->next;
      cnt++;
    }

    pNode = pHead;
    for (int i = 0; i < cnt; ++i) pNode = pNode->next;
    ListNode *pEntry = pHead;
    while (pEntry != pNode) {
      pEntry = pEntry->next;
      pNode = pNode->next;
    }
    return pEntry;
  }
};
