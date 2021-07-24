// "BST-Inorder Traverse, Two-Pointer", Time Complexity: O(n), Space Complexity: O(n). (n: root 노드 갯수)
// 이외에 Hash Set을 이용한 2-Pass 방법(O(n))이 있음.

class Solution {
private:
    vector<int> val;
public:
    bool findTarget(TreeNode* root, int k) {
        LVR(root);
        return twoSum(k);
    }
    
    void LVR(TreeNode* root) {
        if(root->left)    LVR(root->left);
        val.push_back(root->val);
        if(root->right)    LVR(root->right);
    }
    
    bool twoSum(int k) {
        int left = 0, right = val.size()-1;
        while(left<right) {
            if(val[left]+val[right] == k)   return true;
            else if(val[left]+val[right] < k)   left++;
            else    right--;
        }
        return false;
    }
};
