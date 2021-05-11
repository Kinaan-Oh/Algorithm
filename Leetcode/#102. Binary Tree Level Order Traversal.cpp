// 출제의도: "레벨순서 순회", Time Compelxity: O(n).

struct State {
    TreeNode *node;
    int depth;
    State(TreeNode *n, int d):node(n),depth(d){}
};

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> answer;
        if(root==nullptr)   return answer;
        queue<State> que;
        que.push(State(root,0));
        while(!que.empty()) {
            State cur = que.front();
            que.pop();
            if(answer.size()<cur.depth+1)   answer.push_back({});
            answer[cur.depth].push_back(cur.node->val);
            
            if(cur.node->left)    que.push(State(cur.node->left,cur.depth+1));
            if(cur.node->right)    que.push(State(cur.node->right,cur.depth+1));
        }
        return answer;
    }
};
