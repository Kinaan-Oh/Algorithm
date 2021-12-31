// 출제의도: Inorder Traverse, Time Complexity: O(V), Space Complexity: O(V) (V: number of vertices)

class Solution {
private:
    vector<int> nodes;
    
public:
    int minDiffInBST(TreeNode* root) {
        int answer = INT_MAX;
        
        LVR(root);
        for(int i=0;i<nodes.size()-1;i++) {
            answer = min(answer, nodes[i+1]-nodes[i]);
        }
        return answer;
    }
    
    void LVR(TreeNode* root) {
        if(root == nullptr)    return;
        
        LVR(root->left);
        nodes.push_back(root->val);
        LVR(root->right);
    }
};
