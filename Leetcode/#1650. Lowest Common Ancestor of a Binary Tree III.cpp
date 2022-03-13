// LCA, Time Complexity: O(h), Space Complexity: O(1) (h: height of tree)

class Solution {
public:
    Node* lowestCommonAncestor(Node* p, Node * q) {
        unordered_set<Node*>    hashSet;
        
        while(p) {
            hashSet.insert(p);
            p = p->parent;
        }
        while(q) {
            if(hashSet.find(q) != hashSet.end()) {
                return q;
            }
            q = q->parent;
        }
        return nullptr;
    }
};
