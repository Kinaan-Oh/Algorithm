// DFS, Time Complexity: O(n), Space Complexity: O(h) (n: num of nodes, h: height of tree)

class Solution {
private:
    int answer;
    
public:
    int minDepth(TreeNode* root) {
        answer = INT_MAX;
        if(root==nullptr)   return 0;
        minDepth(root, 1);
        return answer;
    }
    
    void minDepth(TreeNode* root, int num) {
        if(root==nullptr)   return;
        else if(root->left==nullptr && root->right==nullptr) {
            answer = min(answer, num);
            return;
        }
        minDepth(root->left, num+1);
        minDepth(root->right, num+1);
    }
};
