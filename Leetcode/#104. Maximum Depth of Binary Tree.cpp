// 출제의도: "DFS/BFS". Time Complexity: O(n), Space Complexity: O(n).

struct Node {
    TreeNode *node;
    int depth;
    Node(TreeNode *n, int d):node(n),depth(d){}
};

class Solution {
private:
    int maximum_depth_of_binary_tree=0;
public:
    int maxDepth(TreeNode* root) {
        queue<Node> que;
        if(root)    que.push(Node(root,1));
        while(!que.empty()) {
            Node cur_node = que.front();
            que.pop();
            maximum_depth_of_binary_tree = max(maximum_depth_of_binary_tree, cur_node.depth);
            
            if(cur_node.node->left)  que.push(Node(cur_node.node->left,cur_node.depth+1));
            if(cur_node.node->right)  que.push(Node(cur_node.node->right,cur_node.depth+1));
        }
        
        return maximum_depth_of_binary_tree;
    }
};
