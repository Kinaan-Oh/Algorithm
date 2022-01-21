// 출제의도: LCA/DFS, Time Complexity: O(n), Space Complexity: O(h) (n: num of nodes, h: max height of tree(lgn ~ n))

class Solution {
private:
    TreeNode* lca = nullptr;
    
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        is_lca(root, p, q);
        return lca;
    }
    
    int is_lca(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == nullptr)    return 0;
        
        int num = 0;
        
        if(root == p || root == q)  num += 1;
        num += is_lca(root->left, p, q);
        num += is_lca(root->right, p, q);
        
        if(num == 2 && lca == nullptr)   lca = root; 
        return num;
    }
};
