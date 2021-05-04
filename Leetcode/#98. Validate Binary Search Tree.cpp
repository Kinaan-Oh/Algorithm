// * BST(L<V<R)는 Inorder Traverse(L->V->R)시 크기가 작은 것부터 큰 순서대로 방문해야만 한다. *

class Solution {
private:
    vector<int> visited;
public:
    // L<V<R
    bool isValidBST(TreeNode* root) {
        inorder(root);
        for(int i=1;i<visited.size();i++) {
            if(visited[i-1]>=visited[i]) return false;
        }
        return true;
    }
    //L->V->R
    void inorder(TreeNode* root) {
        if(root->left)  inorder(root->left);
        visited.push_back(root->val);
        if(root->right) inorder(root->right);
    }
};
