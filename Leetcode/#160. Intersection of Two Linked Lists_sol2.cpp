// "구현", Time Complexity: O(n), Space Complexity: O(1). (n: list의 노드 갯수)
// headA와 headB의 남은 길이가 같고 같은 노드를 가리키면 해당 노드는 intersection 이다.

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int numOfA=0, numOfB=0;
        ListNode* curA = headA, *curB=headB;
        while(curA) {
            numOfA++;
            curA = curA->next;
        }
        while(curB) {
            numOfB++;
            curB = curB->next;
        }
        
        while(!(headA==headB)) {
            if(numOfA>numOfB) {
                headA = headA->next;
                numOfA--;
            }
            else if(numOfA<numOfB) {
                headB = headB->next;
                numOfB--;
            }
            else {
                headA = headA->next;
                headB = headB->next;
                numOfA--;
                numOfB--;
            }
        }
        
        return headA==headB && headA!=nullptr ? headA : nullptr;
    }
};
