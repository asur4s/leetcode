struct DNode{
    int key, value;
    DNode* prev;
    DNode* next;
    DNode(): key(0), value(0), prev(nullptr), next(nullptr){}
    DNode(int k, int v): key(k), value(v), prev(nullptr), next(nullptr){}
};

class LRUCache {
private:
    unordered_map<int, DNode*> _cache;
    DNode *_head;
    DNode *_tail;
    int _size;
    int _capacity;

    DNode* removeTail(){
        DNode *node = _tail->prev;
        removeNode(node);
        return node;
    }

    void removeNode(DNode *node){
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }

    void addNodeToHead(DNode *node){
        _head->next->prev = node;
        node->next = _head->next;
        _head->next = node;
        node->prev = _head;
    }

    void moveToHead(DNode *node){
        removeNode(node);
        addNodeToHead(node);
    }

public:
    LRUCache(int capacity): _capacity(capacity), _size(0) {
        _head = new DNode();
        _tail = new DNode();
        _head->next = _tail;
        _tail->prev = _head;
    }
    
    int get(int key) {
        if(!_cache.count(key)){
            return -1;
        }
        DNode *node = _cache[key];
        moveToHead(node);
        return node->value;
    }
    
    void put(int key, int value) {
        DNode *node, *removed;
        if(!_cache.count(key)){
            node = new DNode(key, value);
            addNodeToHead(node);
            _cache[key] = node;
            _size+=1;
            if(_size > _capacity){
                removed = removeTail();
                _cache.erase(removed->key);
                _size--;
                delete removed;
            }
        }else{
            node = _cache[key];
            node->value = value;
            moveToHead(node);
        }
    }
};