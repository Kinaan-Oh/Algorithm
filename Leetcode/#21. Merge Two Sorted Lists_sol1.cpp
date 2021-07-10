// "iteration", Time Complexity: O(m+n), Space Complexity: O(1) (m: l1 노드 갯수, n: l2 노드 갯수)
// merge sort의 merge 구현 방법과 동일.
// Space Complexity는 기존 l1, l2 노드를 head에 옮겨주는 것이기 때문에 O(1).

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* head = new ListNode();
        ListNode* cur = head;
        while(l1 && l2) {
            if(l1->val <= l2->val) {
                cur->next = l1;
                cur = cur->next;
                l1 = l1->next;
            }
            else {
                cur->next = l2;
                cur = cur->next;
                l2 = l2->next;
            }
        }
        
        if(l1)  cur->next = l1;
        if(l2)  cur->next = l2;
        
        return head->next;
    }
};
