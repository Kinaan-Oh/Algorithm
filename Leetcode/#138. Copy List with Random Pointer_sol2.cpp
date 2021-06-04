// 출제의도: "리스트, 해시테이블, 재귀(그래프 dfs)", Time Complexity: O(n), Space Complexity: O(n). (n: list.length)
// 핵심 아이디어: list를 graph로 간주할 수 있다.
// dfs로 기존 list를 순회하면서, next와 random의 노드가 없다면 생성하여 붙여주고, 이미 생성했다면 붙여주기만 한다. 이미 copied되었는지 파악하기 위해 해시 테이블을 사용한다.

class Solution {
private:
    unordered_map<Node*,Node*>  copied;
    
public:
    Node* copyRandomList(Node* head) {
        if(head==nullptr)   return nullptr;
        if(copied[head])    return  copied[head];
        
        Node* node = new Node(head->val);
        copied[head] = node;
        
        node->next = copyRandomList(head->next);
        node->random = copyRandomList(head->random);
        
        return node;
    }
};
