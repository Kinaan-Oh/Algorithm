// "Hash Table", Time Complexity: O(n), Space Complexity: O(n) (n: list의 노드 갯수)
// headA가 이미 지났던 곳을 headB가 방문한다면 그곳이 교차점이다. 만일 그러한 지점을 만나지 못했다면, 교차점은 없다.

class Solution {
private:
    unordered_set<ListNode*> visited;
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        while(headA) {
            visited.insert(headA);
            headA = headA->next;
        }
        while(headB) {
            if(visited.find(headB)!=visited.end())  return headB;
            headB = headB->next;
        }
        return nullptr;
    }
};
