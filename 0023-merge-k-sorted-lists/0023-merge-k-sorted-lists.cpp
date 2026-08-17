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
    // ListNode* convertLL(vector<int> &arr) {
    //     int n = arr.size();
    //     ListNode* head = new ListNode(-1);
    //     ListNode* temp = head;
    //     for(int i = 0; i < n; i++) {
    //         temp->next = new ListNode(arr[i]);
    //         temp = temp->next;
    //     }
    //     return head->next;
    // }
    // ListNode* mergeKLists(vector<ListNode*>& lists) {
    //     vector<int> arr;
    //     for(auto &temp : lists) {
    //         while(temp) {
    //             arr.push_back(temp->val);
    //             temp = temp->next;
    //         }
    //     }

    //     sort(arr.begin(), arr.end());
    //     ListNode* head = convertLL(arr);
    //     return head;
    // }

    // ListNode* merge2LL(ListNode* list1, ListNode* list2) {
    //     ListNode* dummy = new ListNode(-1);
    //     ListNode* temp = dummy;
    //     ListNode* ptr1 = list1;
    //     ListNode* ptr2 = list2;
    //     while(ptr1 && ptr2) {
    //         if(ptr1->val <= ptr2->val) {
    //             temp->next = ptr1;
    //             ptr1 = ptr1->next;
    //         } else {
    //             temp->next = ptr2;
    //             ptr2 = ptr2->next;
    //         }
    //         temp = temp->next;
    //     }
    //     if(ptr1) temp->next = ptr1;
    //     if(ptr2) temp->next = ptr2;

    //     return dummy->next;
    // }
    
    // ListNode* mergeKLists(vector<ListNode*>& lists) {
    //     int k = lists.size();
    //     if(k == 0) return NULL;
    //     ListNode* list1 = lists[0];
    //     for(int i = 1; i < k; i++) {
    //         list1 = merge2LL(list1, lists[i]);
    //     }
    //     return list1;
    // }

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<
            pair<int, ListNode*>,
            vector<pair<int, ListNode*>>,
            greater<pair<int, ListNode*>>> pq;

        for(auto &temp : lists) {
            if(temp) {
                pq.push({temp->val, temp});
            }
        }

        ListNode* dummy = new ListNode(-1);
        ListNode* temp = dummy;
        while(!pq.empty()) {
            int value = pq.top().first;
            ListNode* node = pq.top().second;
            pq.pop();
            
            temp->next = node;
            temp = temp->next;

            if(node->next) {
                pq.push({node->next->val, node->next});
            }
        }
        return dummy->next;
    }
};