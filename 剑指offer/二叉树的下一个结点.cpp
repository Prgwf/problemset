/*
struct TreeLinkNode {
    int val;
    struct TreeLinkNode *left;
    struct TreeLinkNode *right;
    struct TreeLinkNode *next;
    TreeLinkNode(int x) :val(x), left(NULL), right(NULL), next(NULL) {

    }
};
*/
class Solution {
 public:
  TreeLinkNode* GetNext(TreeLinkNode* pNode) {
    if (pNode == nullptr) {
      return nullptr;
    }

    TreeLinkNode *pNext = nullptr;
    if (pNode->right != nullptr) {
      TreeLinkNode *pRight = pNode->right;

      while (pRight->left != nullptr) {
        pRight = pRight->left;
      }

      pNext = pRight;
    } else if (pNode->next != nullptr){
      TreeLinkNode *pCur = pNode;
      TreeLinkNode *pFa = pNode->next;

      while (pFa != nullptr && pCur == pFa->right) {
        pCur = pFa;
        pFa = pFa->next;
      }

      pNext = pFa;
    }
    return pNext;
  }
};