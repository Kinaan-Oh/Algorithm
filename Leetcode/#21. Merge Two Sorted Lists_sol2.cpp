// "Recursion", Time Complexity: O(m+n), Space Complexity: O(m+n).(m: l1의 노드 갯수, n: l2의 노드 갯수)
// System Stack은 재귀호출로 인해 Worst Case는 Space Complexity: O(m+n).

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(l1==nullptr || l2==nullptr) {
            return (l1==nullptr ? l2 : l1);
        }
            
        ListNode* head = l1->val<=l2->val ? new ListNode(l1->val) : new ListNode(l2->val);
        head->next = l1->val<=l2->val ? mergeTwoLists(l1->next, l2) : mergeTwoLists(l1, l2->next);
        return head;
    }
};
