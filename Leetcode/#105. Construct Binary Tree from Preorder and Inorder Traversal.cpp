// 출제의도: "전위/중위순회 결과로 트리구축", Time Complexity: O(n), Space Complexity: O(n). (n: 트리 노드 갯수)
// LVR, VLR(중위/전위) 혹은 LVR, LRV(중위/후위) 순회 결과가 주어졌을 때, 원래 트리를 생성할 수 있음.(V로 leftsubtree, rightsubtree로 나눌 수 있음)

class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if(preorder.size()==0&&inorder.size()==0)   return nullptr;
        
        int val_of_root = preorder[0];
        int num_of_elem_in_left;
        for(int i=0;i<inorder.size();i++) {
            if(inorder[i]==val_of_root) {
                num_of_elem_in_left = i;
                break;
            }
        }
        
        vector<int> preorder_left(preorder.begin()+1,preorder.begin()+num_of_elem_in_left+1);
        vector<int> preorder_right(preorder.begin()+num_of_elem_in_left+1,preorder.end());
        vector<int> inorder_left(inorder.begin(),inorder.begin()+num_of_elem_in_left);
        vector<int> inorder_right(inorder.begin()+num_of_elem_in_left+1,inorder.end());
        
        return new TreeNode(val_of_root,buildTree(preorder_left,inorder_left),buildTree(preorder_right,inorder_right));
    }
};
