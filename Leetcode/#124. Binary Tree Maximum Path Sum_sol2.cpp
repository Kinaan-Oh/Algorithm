// 출제의도: "이진트리, 재귀", Time Complexity: O(n), Space Complexity: O(h). (n: 노드의 갯수, h: 트리의 최대 깊이)
// sol1과 논리는 동일. 메모이제이션 필요없이 리턴값을 바로 사용하므로 dp를 위한 추가 공간 필요없음. Time Complexity는 O(n)으로 동일하지만, 정밀하게 비교한다면 sol1은 2n번인 반면, sol2는 n번 반복하므로
// sol2가 조금 더 효율적. 재귀의 구현 난이도 측면에서 sol2가 더 어렵고(sol1은 두 모듈을 분리하여 구현하여 메모이제이션이 필수) 굉장히 세련되어 배울 것이 많았던 문제.

class Solution {
private:
    int ans;
public:
    int maxPathSum(TreeNode* root) {
        ans = INT_MIN;
        maxDistToLeaf(root);
        return ans;
    }
    
    int maxDistToLeaf(TreeNode* root) {
        if(root==nullptr)   return 0;
        
        int left = max(0,maxDistToLeaf(root->left));
        int right = max(0,maxDistToLeaf(root->right));
        ans = max(ans, root->val+left+right);
        
        return root->val+max(left,right);
    }
};
