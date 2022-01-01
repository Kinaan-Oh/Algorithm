// 출제의도: LinkedList/Insertion Sort, Time Complexity: O(n^2), Space Complexity: O(n) (n: list 노드 갯수)
// 단순 반복으로 구현가능하지만, divide and conquer 방법을 선택.

class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
        if(head->next == nullptr)   return head;
        
        ListNode* result = insertionSortList(head->next);
        head->next = nullptr;
        
        if(result->val > head->val) {
            head->next = result;
            result = head;
        } else {
            ListNode* prev = nullptr;
            ListNode* cur = result;
            
            while(cur != nullptr) {
                if(cur->val > head->val) {
                    head->next = cur;
                    prev->next = head;
                    break;
                }
                
                prev = cur;
                cur = cur->next;
            }
            if(cur == nullptr)  prev->next = head;
        }
        
        return result;
    }
};
