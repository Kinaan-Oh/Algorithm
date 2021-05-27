// 출제의도: "이진트리, 재귀", Time Complexity: O(n), Space Complexity: O(n). (n: 트리 노드의 갯수)
// 점화식: 어떤 트리의 maximum path sum = max(root를 포함하는 path, leftsubtree의 maximum path sum, rightsubtree의 maximum path sum).
// maxPathSum에서 maxDistToLeaf의 중복호출을 막이 위해 메모이제이션(dp) 사용. 주어지는 트리정보로 각 노드를 식별하기 어려워서 TreeNode*를 키로한 해시테이블을 구성. 

class Solution {
private:
    unordered_map<TreeNode*,int>    dp;    

public:
    int maxPathSum(TreeNode* root) {
        if(root==nullptr)   return INT_MIN;
        
        int pathIncludingRoot = root->val, distLeft = maxDistToLeaf(root->left), distRight = maxDistToLeaf(root->right);
        if(distLeft>=0)     pathIncludingRoot += distLeft;
        if(distRight>=0)    pathIncludingRoot += distRight;
        
        return max(max(maxPathSum(root->left), maxPathSum(root->right)), pathIncludingRoot);
    }
    
    int maxDistToLeaf(TreeNode* root) {
        if(root==nullptr)   return 0;
        if(dp[root])    return dp[root];
        int maxDist = root->val, distLeft = maxDistToLeaf(root->left), distRight = maxDistToLeaf(root->right);
        if(max(distLeft,distRight)>=0)  maxDist += max(distLeft,distRight);
        return dp[root] = maxDist;
    }
};
