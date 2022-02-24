// BST, Time Complexity: O(h), Space Complexity: O(h) (h: height of tree)
// 논리: gap이 minimum인 원소는 반드시 bst 탐색 경로에 포함된다.

class Solution {
private:
    int answer;
    double gap = INT_MAX;
public:
    int closestValue(TreeNode* root, double target) {
        search(root, target);
        return answer;
    }
    
    void search(TreeNode* root, double target) {
        if(root==nullptr)   return;
        
        if(abs(root->val-target)<gap) {
            gap = abs(root->val-target);
            answer = root->val;
        }
        
        if(target<root->val)    search(root->left, target);   
        else if(target>root->val)   search(root->right, target);
        else {
            answer = root->val;
            return;
        }
    }
};
