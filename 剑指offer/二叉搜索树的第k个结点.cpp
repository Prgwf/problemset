/*
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};
*/
class Solution {
 public:
  TreeNode* KthNode(TreeNode* pRoot, int k) {
    if (pRoot == nullptr or k <= 0) {
      return nullptr;
    }

    return dfs(pRoot, k);
  }

  TreeNode *dfs(TreeNode *o, int & k) {
    if (k <= 0) return nullptr;

    TreeNode *pNode = nullptr;

    if (o->left != nullptr) {
      pNode = dfs(o->left, k);
    }

    if (pNode == nullptr) {
      if (k == 1) pNode = o;
      k--;
    }

    if (pNode == nullptr && o->right != nullptr) {
      pNode = dfs(o->right, k);
    }

    return pNode;
  }
};