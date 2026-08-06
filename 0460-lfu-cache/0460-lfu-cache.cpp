class Node {
public:
    int key, value, cnt;
    Node* next;
    Node* prev;
    Node(int key, int value) {
        this->key = key;
        this->value = value;
        next = NULL;
        prev = NULL;
        cnt = 1;
    }
};

class List {
    public:
    int size;
    Node* head;        
    Node* tail;
    List() {
        head = new Node(0, 0);
        tail = new Node(0, 0);
        head->next = tail;
        tail->prev = head;
        size = 0;
    }

    void addFront(Node* node) {
        Node* temp = head->next;            
        node->next = temp;
        temp->prev = node;
        head->next = node;
        node->prev = head;
        size++;
    }

    void removeNode(Node* node) {
        Node* nextNode = node->next;
        Node* prevNode = node->prev;
        nextNode->prev = prevNode;
        prevNode->next = nextNode;
        size--;
    }
};

class LFUCache {
    map<int, List*> freqListMap;
    map<int, Node*> keyNode;
    int maxsize;
    int curSize;
    int minFreq;
    public:

    LFUCache(int capacity) {
        maxsize = capacity;
        curSize = 0;
        minFreq = 0;
    }

    void updateFreqListMap(Node* node) {
        keyNode.erase(node->key);
        freqListMap[node->cnt]->removeNode(node);
        if(node->cnt == minFreq && freqListMap[node->cnt]->size == 0) {
            minFreq++;
        }

        List* nextHigherFreqList;
        if(freqListMap.find(node->cnt + 1) != freqListMap.end()) {
            nextHigherFreqList = freqListMap[node->cnt + 1];
        } else {
            nextHigherFreqList = new List();
        }
        node->cnt += 1;
        nextHigherFreqList->addFront(node);
        freqListMap[node->cnt] = nextHigherFreqList;
        keyNode[node->key] = node;
    }
    
    int get(int key) {
        if(keyNode.find(key) != keyNode.end()) {
            Node* node = keyNode[key];
            int val = node->value;
            updateFreqListMap(node);
            return val;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(maxsize == 0) return;
        if(keyNode.find(key) != keyNode.end()) {
            Node* node = keyNode[key];
            node->value = value;
            updateFreqListMap(node);
        } else {
            if(curSize == maxsize) {
                List* list = freqListMap[minFreq];
                keyNode.erase(list->tail->prev->key);
                freqListMap[minFreq]->removeNode(list->tail->prev);
                curSize--;
            }
            curSize++;
            minFreq = 1;
            List* listFreq = new List();
            if(freqListMap.find(minFreq) != freqListMap.end()) {
                listFreq = freqListMap[minFreq];
            }
            Node* node = new Node(key, value);
            listFreq->addFront(node);
            keyNode[key] = node;
            freqListMap[minFreq] = listFreq;
        }
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */