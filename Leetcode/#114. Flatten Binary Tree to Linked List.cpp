// 출제의도 : "이진트리, 구현(재귀/반복)", Time Complexity: O(n), Space Complexity: O(n). (n: 노드갯수)
// Reculsive 구현방식
class Solution {
public:
    void flatten(TreeNode* root) {
        if(root==nullptr)   return;
        
        flatten(root->left);
        flatten(root->right);
        if(root->left==nullptr) return;
        
        TreeNode *mid = root->left;
        while(mid->right) {
            mid = mid->right;
        }
        mid->right = root->right;
        root->right = root->left;
        root->left=nullptr;
    }
};
