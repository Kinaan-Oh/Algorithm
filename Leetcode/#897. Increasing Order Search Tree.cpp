// Recursion, Time Complexity: O(n), Space Complexity: O(1) (n: num of nodes)
// 논리: 1) increasing 순서대로 방문하기 위해 inorder traverse.
//      2) answer는 root를, cur는 answer의 leaf node를 point.
//      3) increasing scewed binary tree를 형성하기 위해 inorder traverse에 방문하는 노드들을 순서대로 cur의 right에 추가.
//      4) left subtree를 answer에 삽입 후 root->left = nullptr 처리를 해주어야 cycle이 형성되지 않는다.

class Solution {
private:
    TreeNode* answer;
    TreeNode* cur;
public:
    TreeNode* increasingBST(TreeNode* root) {
        answer = new TreeNode();
        cur = answer;
        LVR(root);
        return answer->right;
    }
    
    void LVR(TreeNode* root) {
        if(root==nullptr)   return;
        
        LVR(root->left);
        root->left = nullptr;
        cur->right = root;
        cur = cur->right;
        LVR(cur->right);
    }
};
