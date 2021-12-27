// 출제의도: Balanced Binary Tree/ Recursion with Memoize, Time Complexity: O(n), Space Complexity: O(n). (n: 트리 노드 갯수)
// Balanced Binary Tree : left subtree가 balanced && right substree가 balanced && left subtree height 와 right subtree height 차가 1 이하.
// height 중복계산을 방지하기 위해 memoize 하여 time complexity를 O(n)으로 개선. (memoize하지 않으면 O(nlgn))

class Solution {
private:
    unordered_map<TreeNode*,int> height;
    
public:
    bool isBalanced(TreeNode* root) {
        if(root == nullptr)    return true;
        
        bool balanced = abs(height_of(root->left)-height_of(root->right)) <= 1;
        
        return balanced && isBalanced(root->left) && isBalanced(root->right);
    }
    
    int height_of(TreeNode* root) {
        if(root == nullptr)    return 0;
        if(height.find(root) != height.end())   return height[root];
        
        height[root] = max(height_of(root->left), height_of(root->right)) + 1;
        
        return height[root];
    }
};
