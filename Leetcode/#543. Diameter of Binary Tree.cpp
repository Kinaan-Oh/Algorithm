// 출제의도: "트리 최대 깊이", Time Complexity: O(n), Space Complexity: O(n). (n: TreeNode의 갯수)
// leetcode #104. Maximum Depth of Binary Tree의 응용. DFS을 이용하여 Maximum Depth을 구할 수 있어야 함.

// 트리의 직경(diameter)은 반드시 두 leafnode가 양 끝이 되어야 함. 만일 양 끝이 leafnode가 아니라면, 이는 diameter(최대 길이)가 아니기 때문.
// 주어진 트리는 부모->자식 방향으로만 접근 가능하므로 dfs를 이용하여 모든 리프노드간 거리를 측정하는 방식은 사용할 수 없다.
// 대신, 모든 내부 노드(leafnode가 아닌 노드)를 경유하고 양 끝이 leafnode인 경로를 만들어야 하는데 이는 왼쪽, 오른쪽 자식 방향으로의 최대 깊이를 구하면 된다.
// 모든 노드에 대하여 양 끝이 leafnode인 경로(해답 후보)를 구하고 그중 최댓값을 전체 트리의 diameter로 한다. 임의 노드에 대해 양 끝이 leafnode인 경로는 "왼쪽 최대 깊이 + 오른쪽 최대 깊이" 이다.
// 만일 각 노드에 대해 최대 깊이를 새로 계산하게 된다면 중복 계산의 비효율이 발생한다. 이 문제를 해결하기 위해 각 노드의 최대 깊이를 1번만 계산하도록 해야하는데 이는 간단한 점화식으로 가능함을 알 수 있다.
// "노드 a를 루트로 하는 트리의 최대 깊이 = max(왼쪽 서브트리의 최대 깊이, 오른쪽 서브트리의 최대 깊이)+1"
// 따라서, 자식에서 부모 방향으로 각 노드에 대해 최대 깊이를 1번씩만 계산하면 된다. 계산한 결과를 memoize한 뒤 부모 노드의 최대 깊이 계산시 사용할 수 있지만, 바로 다음(부모)에 사용하게 되므로 memoize할
// 필요없이 재귀로 리턴하여 사용할 수 있다.

class Solution {
private:
    int diameter;
    
public:
    int diameterOfBinaryTree(TreeNode* root) {
        max_depth(root);
        return diameter;
    }
    
    int max_depth(TreeNode* root) {
        if(root==nullptr)   return 0;
        
        int left_depth = max_depth(root->left);
        int right_depth = max_depth(root->right);
        
        diameter = max(diameter, left_depth+right_depth);
        return max(left_depth,right_depth)+1;
    }
};
