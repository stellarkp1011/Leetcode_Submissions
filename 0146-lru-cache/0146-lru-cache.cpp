class Node {
public:
    Node* prev;
    Node* next;
    int key;
    int value;

    Node(int key, int value) {
        this->key = key;
        this->value = value;
        prev = next = NULL;
    }
};

class LRUCache {
private:
    unordered_map<int, Node*> mpp;
    Node *head, *tail;
    int capacity;

    void deleteNode(Node* node) {
        Node* nextNode = node->next;
        Node* prevNode = node->prev;
        nextNode->prev = prevNode;
        prevNode->next = nextNode;
    }

    void insertAtHead(Node* node) {
        Node* nextNode = head->next;
        head->next = node;
        node->prev = head;
        nextNode->prev = node;
        node->next = nextNode;
    }

public:
    LRUCache(int capacity) {
        this->capacity = capacity;
        head = new Node(-1, -1);
        tail = new Node(-1, -1);
        head->next = tail;
        tail->prev = head;
    }
    
    int get(int key) {
        if (mpp.find(key) == mpp.end())
            return -1;

        Node* node = mpp[key];

        deleteNode(node);
        insertAtHead(node);

        return node->value;
    }
    
    void put(int key, int value) {
        if(mpp.find(key) != mpp.end()) {
            Node* node = mpp[key];
            deleteNode(node);
            insertAtHead(node);
            node->value = value;
        } else {
            if(mpp.size() == capacity) {
                Node* node = tail->prev;
                mpp.erase(node->key);
                deleteNode(node);
            }
            Node* node = new Node(key, value);
            mpp[key] = node;
            insertAtHead(node);
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */