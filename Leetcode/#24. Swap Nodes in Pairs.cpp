// List/Iterative, Time Complexity: O(n), Space Complexity: O(1) (n: num of nodes)
// Recursive 방법도 가능하나 Space Complexity O(n).(Call Stack)

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode* cur = head;
        if(!(cur && cur->next))    return head;
        
        head = cur->next;
        ListNode* end = nullptr;
        ListNode* next;
        
        while(cur && cur->next) {
            next = cur->next->next;
            if(end)    end->next = cur->next;
            cur->next->next = cur;
            cur->next = next;
            end = cur;
            cur = cur->next;
        }
        return head;
    }
};
