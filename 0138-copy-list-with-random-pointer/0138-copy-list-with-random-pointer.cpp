/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    // Node* copyRandomList(Node* head) {
    //     Node* temp = head;
    //     unordered_map<Node*, Node*> mpp;
    //     while(temp) {
    //         Node* copyNode = new Node(temp->val);
    //         mpp[temp] = copyNode;
    //         temp = temp->next;
    //     }

    //     temp = head;
    //     while(temp) {
    //         Node* copyNode = mpp[temp];
    //         copyNode->next = mpp[temp->next];
    //         copyNode->random = mpp[temp->random];
    //         temp = temp->next;
    //     }

    //     return mpp[head];
    // }

    Node* insertInBetween(Node* head) {
        Node* temp = head;
        while(temp) {
            Node* newNode = new Node(temp->val);
            newNode->next = temp->next;
            temp->next = newNode;
            temp = temp->next->next;
        }
        return head;
    }

    void connectRandomPointer(Node* head) {
        Node* temp = head;

        while(temp) {
            Node* copyNode = temp->next;
            if(temp->random) {
                copyNode->random = temp->random->next;
            } else {
                copyNode->random = NULL;
            }
            temp = temp->next->next;
        }
    }

    Node* getDeepCopy(Node* head) {
        Node* dummy = new Node(-1);
        Node* res = dummy;
        Node* temp = head;
        while(temp) {
            res->next = temp->next;
            temp->next = temp->next->next;
            
            res = res->next;
            temp = temp->next;
        }
        return dummy->next;
    }
    Node* copyRandomList(Node* head) {
        insertInBetween(head);
        connectRandomPointer(head);
        return getDeepCopy(head);
    }
};