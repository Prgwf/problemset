/*
struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
};*/
class Solution {
public:
  ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) {
    if (pListHead == nullptr or k <= 0)
      return nullptr;

    ListNode *pFast = pListHead;
    for (unsigned int i = 0; i < k - 1; ++i) {
      if (pFast->next != nullptr) {
        pFast = pFast->next;
      } else {
        return nullptr;
      }
    }

    ListNode *pSlow = pListHead;
    while (pFast->next != nullptr) {
      pFast = pFast->next;
      pSlow = pSlow->next;
    }
    return pSlow;
  }
};
