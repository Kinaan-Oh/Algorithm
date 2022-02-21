// DFS, Time Complexity: O(n), Space Complexity: O(h). (n: num of nodes, h: height of tree)

class Solution {
private:
    int answer = 0;
    
public:
    int sumRootToLeaf(TreeNode* root) {
        sumRootToLeaf(root, 0);
        return answer;
    }
    
    void sumRootToLeaf(TreeNode* root, int sum) {
        if(root == nullptr)    return;
        
        sum = (sum<<1) | root->val;
        
        if(root->left == nullptr && root->right == nullptr) {
            answer += sum;
            return;
        }
        sumRootToLeaf(root->left, sum);
        sumRootToLeaf(root->right, sum);
    }
};
