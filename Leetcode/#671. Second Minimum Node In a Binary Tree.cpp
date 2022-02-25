// DFS/Data Type, Time Complexity: O(n), Space Complexity: O(h) (n: num of nodes, h: height of tree)
// 논리: Second Smallest Value : Minimum Of(Child of Smallest Node Which is not equal to Smallest Value)
// val은 INT_MAX를 가질 수 있으므로 answer를 long long 타입, LLONG_MAX으로 설정하는 것이 포인트. (INT_MAX로 하면 answer 여부 판단이 깔끔하지 못함)

class Solution {
private:
    int smallestValue;
    long long answer;
public:
    int findSecondMinimumValue(TreeNode* root) {
        smallestValue = root->val;
        answer = LLONG_MAX;
        dfs(root);
        return answer==LLONG_MAX ? -1 : (int)answer;
    }
    
    void dfs(TreeNode* root) {
        if(root->left==nullptr && root->right==nullptr)    return;
        
        int candidate = max(root->left->val, root->right->val);
        if(candidate!=smallestValue)    answer = min(answer, (long long)candidate);
        
        if(root->left->val==smallestValue)  dfs(root->left);
        if(root->right->val==smallestValue)  dfs(root->right);
    }
};
