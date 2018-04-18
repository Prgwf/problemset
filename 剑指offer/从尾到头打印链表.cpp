/**
*  struct ListNode {
*        int val;
*        struct ListNode *next;
*        ListNode(int x) :
*              val(x), next(NULL) {
*        }
*  };
*/
class Solution {
public:
    vector<int> printListFromTailToHead(ListNode* head) {
      vector<int> ret;
      while (head != nullptr) {
        ret.push_back(head->val);
        head = head->next;
      }
      reverse(ret.begin(), ret.end());
      return ret;
    }
};
