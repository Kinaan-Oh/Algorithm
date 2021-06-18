// "Two-runner-pointer, Reverse list", Time Complexity: O(n), Space Complexity: O(1).
// 1) 리스트의 중간위치를 O(n)으로 찾아 2) 중간을 포함한 이후 부분 리스트를 O(n)으로 역순으로 배치하고 3) 두 부분 리스트를 처음부터 비교하여 전부 같으면 true, 다른 노드가 있으면 false.
// 리스트를 처리하기 위한 2가지 기본 테크닉을 미리 알고 있어야 한다.(Two-runner-pointer로 O(n)으로 mid 찾기, Time Complexity O(n)/Space Complexty O(1)로 리스트를 역순으로 뒤집기)

class Solution {
public:
    bool isPalindrome(ListNode* head) {
        ListNode* endOfFirstHalf = frontOfMid(head);
        ListNode* mid = reverse(endOfFirstHalf->next);
        
        while(mid) {
            if(head->val!=mid->val) return false;
            head = head->next;
            mid = mid->next;
        }
        
        return true;
    }
    
    ListNode* frontOfMid(ListNode* head) {
        ListNode *walker=head, *runner=head;
        while(runner->next && runner->next->next) {
            walker = walker->next;
            runner = runner->next->next;
        }
        return walker;
    }
    
    ListNode* reverse(ListNode* head) {
        ListNode* reversed = nullptr;
        ListNode* cur = head;
        while(cur) {
            ListNode* tmp = cur;
            cur = cur->next;
            tmp->next = reversed;
            reversed = tmp;
        }
        
        return reversed;
    }
};
