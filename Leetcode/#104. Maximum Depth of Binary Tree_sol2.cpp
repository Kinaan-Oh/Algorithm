// Tail Recursion, Time Complexity: O(n), Space Complexity: O(1) (n: 트리 노트 갯수)
// Tail Recursion은 C++ 컴파일러가 Call Stack을 재사용함으로써 메모리 최적화. 꼬리재귀를 사용하지 않는다면 트리의 형태에 따라 Space Complexity는 lgn(완전 이진트리)~n(치우친 이진트리)로 좋지 않다.

class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(root == nullptr) return 0;
        
        return max(maxDepth(root->left), maxDepth(root->right)) + 1;
    }
};
