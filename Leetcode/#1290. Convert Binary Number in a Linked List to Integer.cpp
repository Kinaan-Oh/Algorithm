// Math, Time Complexity: O(n), Space Complexity: O(1) (n: num of nodes)

class Solution {
public:
    int getDecimalValue(ListNode* head) {
        int answer = 0;

        while(head) {
            answer = (answer<<1) | head->val;
            head = head->next;
        }
        return answer;
    }
};
