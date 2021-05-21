// 출제의도: "이진트리, 구현(반복)", Time Complexity: O(n), Space Complexity: O(1).
// Iterative 구현방식(In-place)

class Solution {
public:
    void flatten(TreeNode* root) {
        while(root) {
            TreeNode *left = root->left;
            if(left)
            {
                while(left->right) {
                    left = left->right;
                }
                left ->right = root->right;
                root->right = root->left;
                root->left = nullptr;
            }
            root = root->right;
        }
    }
};
