// 출제의도: "BST", Time Complexity: O(n), Space Complexity: O(n). (n: nums.size)
// 입력으로 주어진 "정렬"된 배열이 힌트. 만일 정렬된 상태가 아니라면, AVL or Red-Black 트리를 고려할 수 있음. 정렬된 상태라면 root의 val을 쉽게 결정 할 수 있고, devide-conquer로 left/right subtree
// 를 생성할 수 있음.
// nums를 노드로 하는 BST는 유일하지 않다. nums가 짝수개인 경우 left mid를 루트로 할 것인지, right mid를 루트로 할 것인지에 따라 모양을 달라진다. 그러나, 어떤 경우든 balanced BST가 성립한다.

class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int mid = nums.size()/2;
        TreeNode* root = new TreeNode(nums[mid], makeSubtree(nums,0,mid), makeSubtree(nums,mid+1,nums.size()));
        return root;
    }
    
    TreeNode* makeSubtree(vector<int>& nums, int begin, int end) {
        if(begin==end)  return nullptr;
        
        int mid = (begin+end)/2;
        TreeNode* root = new TreeNode(nums[mid], makeSubtree(nums,begin,mid), makeSubtree(nums,mid+1,end));
        return root;
    }
};
