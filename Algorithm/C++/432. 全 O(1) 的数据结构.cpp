class AllOne {
private:
    struct Node {
        int cnt;  
        unordered_set<string> stringSet; 
        Node* left;
        Node* right;

        Node() {}
        Node(int _cnt, const string& _str="", Node* _l=nullptr, Node* _r=nullptr) {
            cnt = _cnt;
            stringSet.insert(_str);
            left = _l;
            right = _r;
        }
    };

    Node* head;
    Node* tail;
    unordered_map<string, Node*> pro;

public:
    AllOne() {
        head = new Node(-1);
        tail = new Node(-1);
        head->right = tail;
        tail->left = head;
    }

    void clear(Node* node) {
        if (node->stringSet.empty()) {
            node->left->right = node->right;
            node->right->left = node->left;
        }
    }
    
    void inc(string key) {
        if (pro.count(key) != 0) {
            Node* node = pro[key];
            int cnt = node->cnt;

            Node* next = nullptr;
            if (node->right->cnt == cnt + 1) {
                next = node->right;
            }else {
                next = new Node(cnt + 1, key, node, node->right);
                // 
                node->right->left = node;
                next->right = node->right;
                node->right = next;
                next->right->left = next;
            }
            next->stringSet.insert(key);
            pro[key] = next;

            node->stringSet.erase(key);
            clear(node);
        } else {
            Node* node = nullptr;
            if (head->right->cnt == 1){
                node = head->right;
            } else {
                node = new Node(1, key, head, head->right);
                head->right = node;
                node->right->left = node;
            }
            node->stringSet.insert(key);
            pro[key] = node;
        }
    }
    
    void dec(string key) {
        Node* node = pro[key];
        int cnt = node->cnt;
        if (cnt == 1){
            pro.erase(key);
        } else {
            Node* next = nullptr;
            if (node->left->cnt == cnt - 1){
                next = node->left;
            } else {
                next = new Node(cnt - 1, key, node->left, node);
                node->right->left = node;
                next->right = node->right;
                node->left->right = next;
                node->left = next;
            }
            pro[key] = next;
            next->stringSet.insert(key);
        }
        node->stringSet.erase(key);
        clear(node);
    }
    
    string getMaxKey() {
        for (const auto& str: tail->left->stringSet) return str;
        return "";
    }
    
    string getMinKey() {
        for (const auto& str: head->right->stringSet) return str;
        return "";
    }
};
