// recursion with memoization, Time Complexity: O(n), Space Complexity: O(n). (n: num of nodes)
// failed의 원인은 각 노드에 대해 중복 계산이 발생하기 때문. 따라서, memoization이 필요하고 다음과 같이 정의.
// dp_i[a] : node a를 방문한 경우, a를 root로 하는 트리로 부터 얻을 수 있는 최대 금액 , dp_ni[a] : node a를 방문하지 않은, a를 root로 하는 트리로 부터 얻을 수 있는 최대 금액
// 점화식 : dp_i[a] = dp_ni[left] + dp_ni[right] , dp_ni[a] = max(dp_ni[left], dp_i[left]) + max(dp_ni[right], dp_i[right]).
// root를 방문하지 않은 경우, 자식 노드를 방문하지 않는 경우가 방문하는 경우보다 클 수 있다는 사실에 주의.

class Solution {
private:
    unordered_map<TreeNode*, int>   dp_i;
    unordered_map<TreeNode*, int>   dp_ni;
    
public:
    int rob(TreeNode* root) {
        return max(max_amount(root, true), max_amount(root, false)); 
    }
    
    int max_amount(TreeNode* root, bool include) {
        if(root == nullptr)    return 0;
        
        if(include) {
            if(dp_i.find(root) != dp_i.end())   return dp_i[root];
            
            dp_i[root] = root->val + max_amount(root->left, false) + max_amount(root->right, false);
            return dp_i[root];
        } else {   
            if(dp_ni.find(root) != dp_ni.end())    return dp_ni[root];
            
            dp_ni[root] += max(max_amount(root->left, true), max_amount(root->left, false));
            dp_ni[root] += max(max_amount(root->right, true), max_amount(root->right, false));
            return dp_ni[root];
        }
    }
};
