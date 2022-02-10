// 출제의도: DFS, Time Complexity: O(n), Space Complexity: O(h) (n: num of nodes, h: height of tree)
// lgn<=h<=n
 
class Solution {
private:
    int answer;
    
public:
    int sumNumbers(TreeNode* root) {
        sumNumbers(root, 0);
        return answer;
    }
    
    void sumNumbers(TreeNode* root, int curSum) {
        if(root == nullptr)    return;
        
        curSum = curSum*10 + root->val;
        
        if(root->left == nullptr && root->right == nullptr) {
            answer += curSum;
            return;
        }
        sumNumbers(root->left, curSum);
        sumNumbers(root->right, curSum);
    }
};
