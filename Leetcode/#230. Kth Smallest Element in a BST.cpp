// 출제의도: Tree Treversal, Time Complexituy: O(n), Space Complexity: O(n) (n: num of nodes)

class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        vector<int> path;
        
        LVR(root, path, k);
        return path.back();
    }
    
    bool LVR(TreeNode* node, vector<int> &path, int k) {
        bool ret = false;
        
        if(node->left && LVR(node->left, path, k))    return true;
        
        path.push_back(node->val);
        if(path.size()==k)  return true;

        if(node->right && LVR(node->right, path, k))    return true;
        
        return false;
    }
};
