
class Node {
public:
    int key, value;
    Node* prev;
    Node* next;
    
    Node(int _key, int _value) {
        key = _key;
        value = _value;
        prev = next = nullptr;
    }
};

class LRUCache {
private:
    int capacity;
    unordered_map<int, Node*> cache;
    Node* head;
    Node* tail;

    // Remove a node from the linked list
    void remove(Node* node) {
        Node* prevNode = node->prev;
        Node* nextNode = node->next;
        if (prevNode) prevNode->next = nextNode;
        if (nextNode) nextNode->prev = prevNode;
    }

    // Insert a node at the tail (most recently used)
    void insert(Node* node) {
        Node* prevTail = tail->prev;
        prevTail->next = node;
        node->prev = prevTail;
        node->next = tail;
        tail->prev = node;
    }

public:
    LRUCache(int _capacity) {
        capacity = _capacity;
        head = new Node(0, 0); // Dummy head
        tail = new Node(0, 0); // Dummy tail
        head->next = tail;
        tail->prev = head;
    }
    
    int get(int key) {
        if (cache.find(key) != cache.end()) {
            Node* node = cache[key];
            remove(node);
            insert(node);
            return node->value;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if (cache.find(key) != cache.end()) {
            remove(cache[key]);
            delete cache[key];
        }
        
        Node* node = new Node(key, value);
        cache[key] = node;
        insert(node);
        
        if (cache.size() > capacity) {
            // Remove from head
            Node* lru = head->next;
            remove(lru);
            cache.erase(lru->key);
            delete lru;
        }
    }
};


/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */