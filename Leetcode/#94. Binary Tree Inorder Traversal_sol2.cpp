// Inorder Traverse Iteratively. Time Complexity: O(N), Space Complexity: O(N)(Stack)

class Solution {
private:
    vector<int> visited;
    
public:
    vector<int> inorderTraversal(TreeNode* root) {
        TreeNode *cur = root;
        stack<TreeNode*> st;
        while(!st.empty()||cur)
        {
            if(cur) {
                st.push(cur);
                cur = cur->left;
            }
            
            else {
                cur = st.top();
                st.pop();
                visited.push_back(cur->val);
                cur = cur->right;
            }
        }
        return visited;
    }
};
