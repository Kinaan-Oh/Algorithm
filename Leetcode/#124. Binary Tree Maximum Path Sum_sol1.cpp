// 출제의도: "이진트리, 재귀", Time Complexity: O(2n) = O(n), Space Complexity: O(n). (n: 트리 노드의 갯수)
// 점화식: 어떤 트리의 maximum path sum = max(root를 포함하는 max path sum, leftsubtree의 maximum path sum(root 포함X), rightsubtree의 maximum path sum(root 포함X)).
// maxPathSum에서 maxDistToLeaf의 중복호출을 막이 위해 메모이제이션(dp) 사용. 주어지는 트리정보로 각 노드를 식별하기 어렵기때문에 TreeNode*를 키(key)로 한 해시테이블을 구성. 

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

// 02/12 ReDo: Node Value가 Negative일 수 있다는 점이 문제해결의 핵심. 최적(최대)값을 만들기 위해서는 Negative는 Prune 해야 함.

class Solution {
private:
    unordered_map<TreeNode*,int>    dp;
    
public:
    int maxPathSum(TreeNode* root) {
        if(root == nullptr)    return INT_MIN;
        
        int maxPathSumIncludingRoot = root->val;
        if(maxPathSumToLeaf(root->left)>0)    maxPathSumIncludingRoot += maxPathSumToLeaf(root->left);
        if(maxPathSumToLeaf(root->right)>0)   maxPathSumIncludingRoot += maxPathSumToLeaf(root->right);   

        return max(max(maxPathSum(root->left), maxPathSum(root->right)),
                   maxPathSumIncludingRoot);
    }
    
    int maxPathSumToLeaf(TreeNode* root) {
        if(root == nullptr)    return 0;
        else if(dp.find(root) != dp.end())  return dp[root];
        
        if(maxPathSumToLeaf(root->left)>0)  dp[root] = max(dp[root], maxPathSumToLeaf(root->left));
        if(maxPathSumToLeaf(root->right)>0) dp[root] = max(dp[root], maxPathSumToLeaf(root->right));
        dp[root] += root->val;
        return dp[root];
    }
};
