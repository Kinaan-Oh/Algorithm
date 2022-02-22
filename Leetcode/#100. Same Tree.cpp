// Recursion, Time Complexity: O(n), Space Complexity: O(h) (n: num of nodes, height of tree)
// 논리: 1) Tree p, q의 val이 같고, 2) p, q의 left subtree가 same이고, 3) p, q의 right subtree가 same이면 -> Tree p, q는 same.

class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p==nullptr && q==nullptr)   return true;
        else if(p==nullptr || q==nullptr)    return false;
            
        return p->val==q->val && isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }
};
