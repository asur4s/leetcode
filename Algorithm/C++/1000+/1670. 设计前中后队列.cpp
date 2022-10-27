struct DoubleLinkedListNode {
    int val;
    DoubleLinkedListNode *prev;
    DoubleLinkedListNode *next;
    DoubleLinkedListNode(int x) : val(x), prev(nullptr), next(nullptr) {}
};

class DoubleLinkedList {
private:
    size_t sz;
    DoubleLinkedListNode *head;
    DoubleLinkedListNode *tail;

public:
    DoubleLinkedList();
    ~DoubleLinkedList();

    inline bool empty() { return (sz == 0); }
    inline size_t size() { return sz; }

    void addAtHead(int val);
    void addAtTail(int val);
    int removeAtHead();
    int removeAtTail();
};

DoubleLinkedList::DoubleLinkedList() {
    head = new DoubleLinkedListNode(-1);
    tail = new DoubleLinkedListNode(-1);
    head->next = tail;
    tail->prev = head;
    sz = 0;
}

DoubleLinkedList::~DoubleLinkedList() {
    for (DoubleLinkedListNode *p = head->next; p != tail; p = p->next)
        delete p;
    delete head;
    delete tail;
    head = nullptr;
    tail = nullptr;
    sz = 0;
}

void DoubleLinkedList::addAtHead(int val) {
    DoubleLinkedListNode *toAdd = new DoubleLinkedListNode(val);

    toAdd->next = head->next;
    head->next->prev = toAdd;
    head->next = toAdd;
    toAdd->prev = head;
    ++sz;
}

void DoubleLinkedList::addAtTail(int val) {
    DoubleLinkedListNode *toAdd = new DoubleLinkedListNode(val);
    DoubleLinkedListNode *p = tail->prev;

    toAdd->next = tail;
    tail->prev = toAdd;
    p->next = toAdd;
    toAdd->prev = p;
    ++sz;
}

int DoubleLinkedList::removeAtHead() {
    if (empty()) return -1;

    int ret = -1;
    DoubleLinkedListNode *toRemove = head->next;
    head->next = toRemove->next;
    toRemove->next->prev = head;
    ret = toRemove->val;
    delete toRemove;
    --sz;

    return ret;
}

int DoubleLinkedList::removeAtTail() {
    if (empty()) return -1;

    int ret = -1;
    DoubleLinkedListNode *toRemove = tail->prev;
    DoubleLinkedListNode *p = toRemove->prev;
    p->next = tail;
    tail->prev = p;
    ret = toRemove->val;
    delete toRemove;
    --sz;

    return ret;
}

class FrontMiddleBackQueue {
private:
    DoubleLinkedList *q1;
    DoubleLinkedList *q2;

public:
    FrontMiddleBackQueue() {
        q1 = new DoubleLinkedList();
        q2 = new DoubleLinkedList();
    }
    
    inline size_t size() { return q1->size() + q2->size(); }
    inline bool empty() { return size() == 0; }

    void pushFront(int val) {
        q1->addAtHead(val);
        if ((size() & 1) == 1) {
            int q1_tail = q1->removeAtTail();
            q2->addAtHead(q1_tail);
        }
    }
    
    void pushMiddle(int val) {
        if ((size() & 1) == 1) {
            q1->addAtTail(val);
        }
        else {
            q2->addAtHead(val);
        }
    }
    
    void pushBack(int val) {
        q2->addAtTail(val);
        if ((size() & 1) == 0) {
            int q2_head = q2->removeAtHead();
            q1->addAtTail(q2_head);
        }
    }
    
    int popFront() {
        if (empty()) return -1;
        if ((size() & 1) == 1) {
            int q2_head = q2->removeAtHead();
            q1->addAtTail(q2_head);
        }
        return q1->removeAtHead();
    }
    
    int popMiddle() {
        if (empty()) return -1;
        if ((size() & 1) == 1) {
            return q2->removeAtHead();
        }
        return q1->removeAtTail();
    }
    
    int popBack() {
        if (empty()) return -1;
        int ret = q2->removeAtTail();
        if ((size() & 1) == 1) {
            int q1_tail = q1->removeAtTail();
            q2->addAtHead(q1_tail);
        }
        return ret;
    }
};