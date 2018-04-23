/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
 public:
  TreeNode* reConstructBinaryTree(vector<int> pre, vector<int> vin) {
    int psize = pre.size();
    int vsize = vin.size();

    preOrder = pre;
    inOrder = vin;
    if (psize == 0 or vsize == 0 or psize != vsize) {
      return nullptr;
    }

    return build(0, psize - 1, 0, vsize - 1);
  }

  TreeNode *build(int preOrderStart, int preOrderEnd, int inOrderStart, int inOrderEnd) {
    TreeNode *o = new TreeNode(preOrder[preOrderStart]);
    o->left = o->right = nullptr;

    if (preOrderStart == preOrderEnd) {
      if (inOrderStart == inOrderEnd && preOrder[preOrderStart] == inOrder[inOrderStart]) {
        return o;
      } else {
        return nullptr;
      }
    }
    
    int pos;
    for (pos = inOrderStart; pos <= inOrderEnd; ++pos) {
      if (inOrder[pos] == o->val) {
        break;
      }
    }

    if (pos == inOrderEnd && inOrder[pos] != o->val) {
      return nullptr;
    }

    int leftLength = pos - inOrderStart;
    int leftPreOrderEnd = preOrderStart + leftLength;

    if (leftLength > 0) {
      o->left = build(preOrderStart + 1, leftPreOrderEnd, 
        inOrderStart, pos - 1);
    }
    if (leftLength < preOrderEnd - preOrderStart) {
      o->right = build(leftPreOrderEnd + 1, preOrderEnd, 
        pos + 1, inOrderEnd);
    }

    return o;
  }
private:
  vector<int> preOrder;
  vector<int> inOrder;
} ;