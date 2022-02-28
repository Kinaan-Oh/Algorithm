// Two-Pointer, Time Complexity: O(n), Space Complexity: O(1) (n: num of nodes)

class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode* walker = head;
        ListNode* runner = head;
        
        while(runner && runner->next) {
            walker = walker->next;
            runner = runner->next->next;
        }
        return walker;
    }
};
