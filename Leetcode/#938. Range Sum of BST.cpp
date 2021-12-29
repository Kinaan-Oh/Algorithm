// 출제의도: search using BST, Time Complexity: O(V), Space Complexity: O(V) (V; num of vertices)
// inorder traverse로 brute force하게 해결할 수 있지만, promising한 방향으로 탐색하면 time complexity를 개선할 수 있다.

class Solution {
public:
    int rangeSumBST(TreeNode* root, int low, int high) {
        if(root == nullptr)    return 0;
        
        if(root->val<low)   return rangeSumBST(root->right, low, high);
        else if(root->val>high) return rangeSumBST(root->left, low, high);
        else {
            return root->val+rangeSumBST(root->left, low, high)+rangeSumBST(root->right, low, high);
        }
    }
};
