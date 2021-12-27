// level-order-traverse, Time Complexity: O(n), Space Complexity: O(n). (n: 트리 노드 갯수)
// level 순으로 노드를 순회하며 left, right subtree를 invert.

class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        queue<TreeNode*>    que;
        if(root)    que.push(root);
        
        while(!que.empty()) {
            TreeNode* cur = que.front();
            que.pop();
            swap(cur->left, cur->right);
            
            if(cur->left)   que.push(cur->left);
            if(cur->right)    que.push(cur->right);
        }
        
        return root;
    }
};
