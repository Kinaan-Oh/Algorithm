// Recursion, Time Complexity: O(n), Space Complexity: O(h) (n: num of nodes, h: height of tree)
// 논리) Left Leaf: 1) parent의 left child이고, 2) child node가 없으면 -> left leaf 이다.

class Solution {
public:
    int sumOfLeftLeaves(TreeNode* root) {
        int answer = 0;
        answer += sumOfLeftLeaves(root->left, true);
        answer += sumOfLeftLeaves(root->right, false);
        return answer;
    }
    
    int sumOfLeftLeaves(TreeNode* root, bool left) {
        if(root == nullptr)    return 0;
        else if(left && root->left==nullptr && root->right==nullptr)    return root->val;
        
        int sum = 0;
        sum += sumOfLeftLeaves(root->left, true);
        sum += sumOfLeftLeaves(root->right, false);
        return sum;
    }
};
