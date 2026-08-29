/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    int lengthLL(ListNode* head) {
        int cnt = 0;
        while(head) {
            cnt++;
            head = head->next;
        }
        return cnt;
    }

    ListNode* findTail(ListNode* temp) {
        while(temp->next) {
            temp = temp->next;
        }
        return temp;
    }
    ListNode* rotateRight(ListNode* head, int k) {
        int len = lengthLL(head);
        if(head == NULL) return head;
        if(k % len == 0) return head;
        k = k % len;
        ListNode* temp = head;
        ListNode* tail = findTail(temp);
        tail->next = head;
        int cnt = len - k;
        for(int i = 1; i < cnt; i++) {
            temp = temp->next;
        }
        head = temp->next;
        temp->next = NULL;
        return head;
    }
};