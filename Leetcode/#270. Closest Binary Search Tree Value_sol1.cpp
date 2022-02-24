// Inorder Traverse, Time Complexity: O(n), Space Complexity: O(n) (n: num of nodes)

class Solution {
private:
    vector<int> nodes;
    
public:
    int closestValue(TreeNode* root, double target) {
        int answer;
        double gap = INT_MAX;
        
        LVR(root);
        for(int i=0;i<nodes.size();i++) {
            if(abs(nodes[i]-target)<gap) {
                answer = nodes[i];
                gap = abs(nodes[i]-target);
            }
        }
        return answer;
    }
    
    void LVR(TreeNode* root) {
        if(root==nullptr)   return;
        
        LVR(root->left);
        nodes.push_back(root->val);
        LVR(root->right);
    }
};
