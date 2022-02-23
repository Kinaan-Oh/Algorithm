// DFS, Time Complexity: O(n), Space Complexity: O(h) (n: num of nodes, h: height of tree)

class Solution {
private:
    unordered_map<int, int>    parent;
    unordered_map<int, int>    depth; 
public:
    bool isCousins(TreeNode* root, int x, int y) {
        isCousins(root, x, y, 0, 0);
        return parent[x]!=parent[y] && depth[x]==depth[y];
    }
    
    void isCousins(TreeNode* root, int x, int y, int p, int d) {
        if(root==nullptr)   return;
        else if(root->val==x) {
            depth[x] = d;
            parent[x] = p;
        } else if(root->val==y) {
            depth[y] = d;
            parent[y] = p;
        }
        
        isCousins(root->left, x, y, root->val, d+1);
        isCousins(root->right, x, y, root->val, d+1);
    }
};
