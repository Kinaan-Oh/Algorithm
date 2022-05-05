// Recursion/List, Time Complexity: O(n), Space Complexity: O(1) (n: num of nodes)

class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head==nullptr)   return nullptr;
        
        ListNode* end = head;
        ListNode* next;
        
        for(int i=0;i<k-1;i++) {
            end = end->next;
            if(end==nullptr)    return head;
        }
        next = end->next;
        reverse(head, end);

        head->next = reverseKGroup(next, k);
        return end;
    }
    
    void reverse(ListNode* head, ListNode* tail) {
        ListNode* prev = nullptr;
        ListNode* cur = head;
        ListNode* next;
        
        while(prev!=tail) {
            next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next;
        }
    }
};
