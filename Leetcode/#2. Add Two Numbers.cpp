// 출제의도: "List, Math", Time Complexity: O(max(m,n)), Space Complexity: O(m+n). (m: l1.size, n:l2,size)

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* answer = new ListNode(-1);   // dummy
        ListNode* cur = answer;
        int carry = 0;
        while(l1 && l2) {
            int sum = l1->val + l2->val + carry;
            cur->next = new ListNode(sum%10);
            cur = cur->next;
            carry = sum/10;
            l1 = l1->next;
            l2 = l2->next;
        }
        while(l1) {
            int sum = l1->val + carry;
            cur->next = new ListNode(sum%10);
            cur = cur->next;
            carry = sum/10;
            l1 = l1->next;
        }
        while(l2) {
            int sum = l2->val + carry;
            cur->next = new ListNode(sum%10);
            cur = cur->next;
            carry = sum/10;
            l2 = l2->next;
        }
        if(carry)   cur->next = new ListNode(carry);
        
        return answer->next;
    }
};
