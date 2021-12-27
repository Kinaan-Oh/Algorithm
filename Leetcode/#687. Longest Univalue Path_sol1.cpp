// 출제의도: Diameter Of BinaryTree/ Depth Of BinaryTree, Time Complexity: O(n), Space Complexity: O(h). (lgn<=h<=n)
// 기본적으로 Depth 개념을 이용한 Diameter Of BinaryTree 구하는 논리를 채택. Univalue를 고려해야한다는 것이 차이점이지만, 무리없이 구현할 수 있음.

class Solution {
private:
    unordered_map<TreeNode*, int>   depth;
    
public:
    int longestUnivaluePath(TreeNode* root) {
        maxDepth(root);
        
        return diameter(root);
    }
    
    int diameter(TreeNode* root) {
        if(root == nullptr)    return 0;
        
        int path_across_root = 0;
        if(root->left && root->left->val == root->val) {
            path_across_root += depth[root->left];
        }
        if(root->right && root->right->val == root->val) {
            path_across_root += depth[root->right];
        }
        
        return max(max(diameter(root->left), diameter(root->right)), path_across_root);
    }
    
    int maxDepth(TreeNode* root) {
        if(root == nullptr)    return 0;
        
        int left = maxDepth(root->left);
        int right = maxDepth(root->right);
        
        if(root->left && root->left->val == root->val) {
            depth[root] = left;
        }
        if(root->right && root->right->val == root->val) {
            depth[root] = max(depth[root], right);
        }
        depth[root] += 1;
        
        return depth[root];
    }
};
