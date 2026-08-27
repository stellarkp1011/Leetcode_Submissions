/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    // ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    //     ListNode* temp = headA;
    //     unordered_map<ListNode*, int> mpp;

    //     while(temp) {
    //         mpp[temp] = 1;
    //         temp = temp->next;
    //     }

    //     ListNode* temp2 = headB;
    //     while(temp2) {
    //         if(mpp.find(temp2) != mpp.end()) return temp2;
    //         temp2 = temp2->next;
    //     }
    //     return NULL;
    // }

    // ListNode *collision(ListNode *headA, ListNode *headB, int d) {
    //     ListNode* temp = headA;
    //     ListNode* temp2 = headB;
    //     while(d != 0) {
    //         d--;
    //         temp2 = temp2->next;
    //     }

    //     while(temp != temp2) {
    //         temp = temp->next;
    //         temp2 = temp2->next;
    //     }

    //     return temp;
    // }

    // ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    //     ListNode* temp = headA;
    //     ListNode* temp2 = headB;
    //     int n1 = 0;
    //     int n2 = 0;
    //     while(temp) {
    //         n1++;
    //         temp = temp->next;
    //     }
    //     while(temp2) {
    //         n2++;
    //         temp2 = temp2->next;
    //     }

    //     if(n1 < n2) return collision(headA, headB, n2 - n1);
    //     else return collision(headB, headA, n1 - n2);
    // }

    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(headA == NULL || headB == NULL) return NULL;
        ListNode* temp = headA;
        ListNode* temp2 = headB;

        while(temp != temp2) {
            temp = temp->next;
            temp2 = temp2->next;

            if(temp == temp2) return temp;
            
            if(temp == NULL) temp = headB;
            if(temp2 == NULL) temp2 = headA;
        }

        return temp;
    }
};