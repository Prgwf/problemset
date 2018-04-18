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
  ListNode* FindFirstCommonNode( ListNode* pHead1, ListNode* pHead2) {
    if (pHead1 == nullptr or pHead2 == nullptr) {
      return nullptr;
    }

    int L1= GetLength(pHead1);
    int L2= GetLength(pHead2);
    ListNode *pLong, *pShort;
    int d;
    if (L1 > L2) {
      pLong = pHead1;
      pShort = pHead2;
      d = L1 - L2;
    } else {
      pLong = pHead2;
      pShort = pHead1;
      d = L2 - L1;
    }

    for (int i = 0; i < d; ++i) {
      pLong = pLong->next;
    }
    ListNode *pNode = nullptr;
    while (pLong != nullptr and pShort != nullptr) {
      if (pLong->val == pShort->val) {
        pNode = pLong;
        break;
      }
      pLong = pLong->next;
      pShort = pShort->next;
    }
    return pNode;
  }

  int GetLength(ListNode *pHead) {
    int ret = 0;
    while (pHead != nullptr) {
      ret++;
      pHead = pHead->next;
    }
    return ret;
  }
};
