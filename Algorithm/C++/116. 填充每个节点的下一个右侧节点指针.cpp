class Solution {
public:
    Node* connect(Node* root) {
        if(root == NULL){
            return root;
        }
        queue<Node *> q;
        Node* node;
        q.push(root);
        int size, i;

        while(!q.empty()){
            size = q.size();
            for(i=0; i<size; i++){
                node = q.front();
                q.pop();

                if(i<size - 1){
                    node->next = q.front();
                }
                if(node->left){
                    q.push(node->left);
                }
                if(node->right){
                    q.push(node->right);
                }
            }
        }
        return root;
    }
};